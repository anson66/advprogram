#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    vector<string> words;

    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    for (vector<string>::iterator it = words.begin(); it != words.end(); it++) {
        cout << *it << endl;
    }

    sort(words.begin(), words.end(), greater<string>());
    //C++11
    for (auto const& x : words) {
        cout << x << endl ;
    }
}
