#include <iostream>
#include <set>

using namespace std;

int main ()
{
    set<string> word_set;
    string word;

    while (cin >> word) {
        word_set.insert(word);
    }

    for (set<string>::iterator i = word_set.begin(); i != word_set.end(); i++)
        cout << *i << endl;

    //C++11
    for (auto const& word : word_set) {
        cout << word << endl;
    }
}
