#include <iostream>

using namespace std;

void print(int* y, int N)
{
    for (int  x = 0; x < N; x++) {
         for (int col=0; col < N; col++)
               if (col == y[x]) cout << " *";
                else cout << " .";
        cout << endl;
    }
    cout << endl;
}

bool threatens(int x1, int y1, int x2, int y2)
{
    return x1==x2 || y1==y2 || x1+y1 == x2+y2 || x1-y1 == x2-y2;
}

bool safe (int * y, int x)
{
    for (int i = 0; i < x; i++)
        if (threatens(i, y[i] , x, y[x])) return false;
    return true;
}

int vet(int x, int* y, int N)
{
    if (x==N) return 1;

    int count = 0;
    for (int i = 0; i < N; i++) {
        y[x] = i;
        if (safe(y, x))
            count += vet(x+1, y, N);
    }
    return count;
}


int main(int argc, char** argv)
{
    int N;
    int y[100];  // x, y[x] la toa do cua 1 con hau
    cin >> N;

    cout << vet(0, y, N);
}
