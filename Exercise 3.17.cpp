#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    vector<string> words;
    string word;
    while (cin >> word)
        words.push_back(word);
    for (auto &str : words)
        for (auto &ch : str)
            ch = toupper(ch);
    for (decltype(words.size()) index = 0; index < words.size(); ++index){
        cout << words[index] << " ";
        if (index % 8 == 7)
            cout << endl;
    }
    return 0;
}
