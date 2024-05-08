#include<iostream>
#include<iomanip>
#include<fstream>

#include<numeric>
#include<algorithm>
#include<cmath>
#include<cassert>

#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<array>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define rforn(i, n) for (int i = int(n) - 1; ~i; i--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define ft first
#define sd second
#define pb push_back


typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;



void solve1() {
    cout << '\n';
}

void solve2() {
    cout << '\n';
}

void solve3() {
    cout << '\n';
}

void solve4() {
    cout << '\n';
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << fixed << setprecision(21);

    int num = -1;
    while (cin >> num && num > -1) {
        cin >> num;
        switch (num) {
        case 1: // number of vertices with one left child
            solve1();
            break;
        case 2:
            solve2();
            break;
        case 3:
            solve3();
            break;
        case 4:
            solve4();
            break;
        default:
            cout << "No such task!\n";
            num = -1;
            break;
        }
    }
}

