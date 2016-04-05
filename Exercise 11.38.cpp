#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void word_transform(ifstream &map_file, ifstream &input);
unordered_map<string, string> buildMap(ifstream &map_file);
const string& transform(const string &s, const unordered_map<string, string> &m);
int main()
{
    ifstream map_file("map_file.txt");
    ifstream input("input.txt");
    word_transform(map_file, input);
    return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);    // store the transformations
    string text;                            // hold each line from the input
    while (getline(input, text)) {          // read a line of input
        istringstream stream(text);         // read each word
        string word;
        bool firstword = true;              // controls whether a space is printed
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";                // print a space between words
            // transform returns its first argument or its transformation
            cout << transform(word, trans_map); // print the output
        }
        cout << endl;                       // done with this line of input
    }
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> trans_map;  // holds the transformations
    string key;     // a word to transform
    string value;   // phrase to use instead
    // read the first word into key and the rest of the line into value
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)   // check that there is a transformation
            trans_map[key] = value.substr(1);   // skip leading space
        else
            throw runtime_error("no rule for " + key);
    return trans_map;
}

const string& transform(const string &s, const unordered_map<string, string> &m)
{
    // the actual map work; this part is the heart of the program
    auto map_it = m.find(s);
    // if this word is in the transformation map
    if (map_it != m.cend())
        return map_it->second;  // use the replacement word
    else
        return s;               // otherwise rethrn the original unchanged
}