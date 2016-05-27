#include "TextQuery.h"
using namespace std;
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text)) {         // for each line in the file
		file->push_back(text);      // remember this line of text
		int n = file->size() - 1;       // the current line number
		istringstream line(text);       // separate the line into words
		string word;
		while (line >> word) {
			if (!isalnum(word.back()))
				word.pop_back();
			// if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word]; // lines is a shared_ptr
			if (!lines) // that pointer is null the first time we see word
				lines.reset(new set<line_no>);  // allocate a new set
			lines->insert(n);   // insert this line number
		}
	}
}

QueryResult TextQuery::query(const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// use find and not a subscript to avoid addign words to wm!
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);   // not found
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
	// if the word was found, print the count and all occurrences
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	// print each line in which the word appeared
	for (auto num : *qr.lines)  // for every element in the set
								// don't confound the user with text lines starting at 0
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << endl;
	return os;
}

string make_plural(set<TextQuery::line_no>::size_type size, const string &base, const string &suffix)
{
	return (size == 1 ? base : base + suffix);
}