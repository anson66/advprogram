#include <iostream>
#include <map>

using namespace std;

int main ()
{
    map<string,int> count;
    string word;

    while (cin >> word) {
        count[word] += 1;
    }

    for (map<string, int>::iterator i = count.begin(); i != count.end(); i++) {
        cout << i->first << ":" << i->second << endl;
    }

    //C++11
    for (auto const& x : count) {
        cout << x.first << ':' << x.second << endl ;
    }
}
