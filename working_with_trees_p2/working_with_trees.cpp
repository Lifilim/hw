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



template<typename T>
struct queue {
    struct nodeQueue {
        T val;
        nodeQueue* next = nullptr;
    };

    nodeQueue* tail = new nodeQueue;
    nodeQueue* head = tail;
    int SIZE = 0;

    void push(T value) {
        nodeQueue* sub_tail = new nodeQueue;
        tail->val = value;
        tail->next = sub_tail;
        swap(tail, sub_tail);
        ++SIZE;
    }
    bool empty() {
        return tail == head;
    }
    T front() {
        assert(!empty());
        return head->val;
    }
    T pop() {
        assert(!empty());
        nodeQueue* cur = head;
        head = head->next;
        T value = cur->val;
        delete cur;
        --SIZE;
        return value;
    }
    int size() {
        return SIZE;
    }
    T max_value() {
        assert(!empty());
        nodeQueue* cur = head;
        T max_v = cur->val;
        cur = cur->next;
        while (cur != tail) {
            max_v = max(max_v, cur->val);
            cur = cur->next;
        }
        return max_v;
    }

    friend ostream& operator<<(ostream& out, queue q) {
        if (!q.empty()) cout << q.pop();
        while (!q.empty()) cout << ' ' << q.pop();
        return out;
    }
};




template<typename T>
class tree {
private:
    struct node {
        T val;
        tree* left = nullptr;
        tree* right = nullptr;
        tree* parent = nullptr;
    };
    node* root = nullptr;

    public:
    void add(T x) {
        node *n = new node;
        n->val = x;
        if (this->root) {
            node *t = this->root;
            while (t) 
                if (n->val > t->val) 
                    if (t->right)
                        t = t->right;
                    else {
                        n->parent = t;
                        t->right = n;
                        break;
                    }
                else if (n->val < t->val)
                    if (t->left)
                        t = t->left;
                    else {
                        n->parent = t;
                        t->left = n;
                        break;
                    }
        } else this = n;
    }

    void input() {
        string s;
        getline(cin, s);
        stringstream sin(s);
        T v;
        while (sin >> v) add(v);
    }

    void inorder(auto comp, node* v = nullptr, bool ok = true) {
        if (ok && v == nullptr) v = root;
        if (v) {
            this->tree::inorder(comp, v->left, false);
            //if (v->left && !v->right)
            if (comp)
                cout << v->val << ' ';
            this->tree::inorder(comp, v->right, false);
        }
    }

    node* find(T x, node *v = root) {
        if (!v || v->val) return v;
        if (x < v->val) return find(x, v->left);
        else return find(x, v->right);
    }
};


void solve1() {
    tree<int> tr;
    tr.inorder([](auto v) {return v->left && !v->right; });
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

