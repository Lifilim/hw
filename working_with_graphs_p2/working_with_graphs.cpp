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
    int n, m;
    cout << "Enter vertices and edges number: ";
    cin >> n >> m;
    if (n <= 0 || m < 0) {
        cout << "It isn't a graph!\n";
        return;
    }
    vector<vector<int>> g(n);
    if (m > 0) cout << "Enter edges: \n";
    forn(mm, m) {
        int v, u;
        cin >> v >> u;
        g[v - 1].pb(u - 1);
        if (v != u) g[u - 1].pb(v - 1);
    }
    int a, b;
    cout << "Enter edge (A and B): ";
    cin >> a >> b;
    --a, --b;
    auto ita = find(all(g[a]), b);
    if (ita == g[a].end()) cout << "No such edge\n";
    else {
        g[a].erase(ita);
        auto itb = find(all(g[b]), a);
        if (itb != g[b].end()) g[b].erase(itb);
        cout << "The rest of the edges: " << '\n';
        bool ex = false;
        forn(v, n) for (int u : g[v]) if (v <= u) {
            cout << v + 1 << ' ' << u + 1 << '\n';
            ex = true;
        }
        if (!ex) cout << "no such edges\n";
    }
}

void solve3() {
    int n, m;
    cout << "Enter vertices and edges number: ";
    cin >> n >> m;
    if (n <= 0 || m < 0) {
        cout << "It isn't a graph!\n";
        return;
    }
    vector<vector<int>> g(n);
    if (m > 0) cout << "Enter edges: \n";
    forn(mm, m) {
        int v, u;
        cin >> v >> u;
        g[v - 1].pb(u - 1);
    }
    cout << "Answer: "<< '\n';
    forn(i, n) 
        cout << "for " << i + 1 << " vertex: " << g[i].size() << '\n';
    
}

void dfs(vector<vector<int>>& g, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : g[v])
        if (!visited[u]) dfs(g, u, visited);
}

void solve4() {
    int n, m;
    cout << "Enter vertices and edges number: ";
    cin >> n >> m;
    if (n <= 0 || m < 0) {
        cout << "It isn't a graph!\n";
        return;
    }
    vector<vector<int>> g(n);
    if (m > 0) cout << "Enter edges: \n";
    forn(mm, m) {
        int v, u;
        cin >> v >> u;
        g[v - 1].pb(u - 1);
        if (v != u) g[u - 1].pb(v - 1);
    }
    vector<bool> visited(n);
    dfs(g, 0, visited);
    bool connected = true;
    forn(i, n) connected = connected && visited[i];
    cout << "Answer: " << (connected ? "YES" : "NO" ) << '\n';
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
        case 2: // remove edge
            solve2();
            break;
        case 3: // calculate the outdegree of each vertex
            solve3();
            break;
        case 4: // is the graph connected
            solve4();
            break;
        case 5: // 
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

