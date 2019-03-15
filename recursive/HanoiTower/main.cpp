#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<int> column[SIZE];

void display(int disk, int source, int dest)
{
    cout << disk << " from " << source << " -> " << dest << endl;
    for (int col = 0; col < 3; col ++) {
        cout << "|";
        for (int i = 0; i < column[col].size(); i++) cout << column[col][i];
        cout << endl;
    }
}

void move(int source, int dest)
{
    int disk = column[source].back();
    column[source].pop_back();
    column[dest].push_back(disk);
    display(disk, source, dest);
}

void solve(int n, int source, int dest, int intermediate)
{
    if (n <= 1) move(source, dest);
    else {
        solve(n-1, source, intermediate, dest);
        solve(1, source, dest, intermediate);
        solve(n-1, intermediate, dest, source);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) column[0].push_back(i);
    solve(n, 0, 1, 2);
}
