#include "Query_base.h"
#include "TextQuery.h"
using namespace std;
void runQueries(ifstream &ifs);
int main()
{
	ifstream ifs("Story.txt");
	runQueries(ifs);
	return 0;
}
void runQueries(ifstream &ifs)
{
	cout << "Executing Query for: ";
	TextQuery tq(ifs);
	string line;
	getline(cin, line);
	vector<string> word_seq;
	vector<string> sym_seq;
	auto siter = line.begin();
	while (siter != line.end()) {
		if (isalnum(*siter)) {
			auto end = siter;
			while (end != line.end() && isalnum(*end))
				++end;
			word_seq.push_back(string(siter, end));
			siter = end;
		}
		else {
			if (*siter != ' ')
				sym_seq.push_back(string(1, *siter));
			++siter;
		} 
	}
	auto witer = word_seq.begin(), symiter = sym_seq.begin();
	Query q(word_seq.front());
	while (symiter != sym_seq.end()) {
		if (*symiter == "~")
			q = ~q;
		else if (*symiter == "|")
			q = q | *++witer;
		else if (*symiter == "&")
			q = q & *++witer;
		++symiter;
	}
	print(cout, q.eval(tq)) << endl;
}