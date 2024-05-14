#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>

#include<numeric>
#include<algorithm>
#include<cmath>
#include<cassert>

#include<vector>
#include<set>
#include<map>
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
    int n, m;
    cout << "Enter vertices and edges number: ";
    cin >> n >> m;
    if (n <= 0 || m < 0) {
        cout << "It isn't a graph!\n"; 
        return;
    }
    vector<set<int>> g(n);
    if (m > 0) cout << "Enter edges: \n";
    forn(mm, m) {
        int v, u;
        cin >> v >> u;
        g[v - 1].insert(u - 1);
        g[u - 1].insert(v - 1);
    }
    forn(i, n) 
        g[i].insert(i);
    int q;
    cout << "Enter request number: ";
    cin >> q;
    forn(qq, q) {
        int v;
        cout << "Enter verticies: ";
        cin >> v;
        cout << "Answer: ";
        auto it = g[v - 1].begin();
        bool ex = false;
        forn(i, n) {
            if (it == g[v - 1].end() || *it > i) {
                cout << i + 1 << ' ';
                ex = true;
            } else ++it;
        }
        if (!ex) cout << "no such vertices";
        cout << '\n';
    }
}

void solve2() {
   
    cout << "Answer: "<< '\n';
}

void solve3() {
   
    cout << "Answer: "<< '\n';
}

void solve4() {
   
    cout << "Answer: "<< '\n';
}

void solve5() {
   
    cout << "Answer: "<< '\n';
}


int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << fixed << setprecision(21);

    int num = -1;
    cout << "Enter task numder: ";
    while (cin >> num && num > -1) {
        cin.get();
        switch (num) {
        case 1: // print all vertices not adjacent to this one
            solve1();
            break;
        case 2: // tree depth
            solve2();
            break;
        case 3: // leaves' sum
            solve3();
            break;
        case 4: // vertices of level k
            solve4();
            break;
        case 5: // vertices of level k
            solve5();
            break;
        default:
            cout << "No such task!\n";
            num = -1;
            break;
        }
        cout << '\n';
        if (num > -1) 
            cout << "Enter task numder: ";
    }
}

