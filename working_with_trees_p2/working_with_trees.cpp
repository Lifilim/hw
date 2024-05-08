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
    void make_empty() {
        while (!empty()) pop();
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
struct tree {
    struct node {
        T val;
        node* left = nullptr;
        node* right = nullptr;
        node* parent = nullptr;
    };
    node* root = nullptr;

//////////////////////////////////////////////////

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
        } else this->root = n;
    }

    void input() {
        string s;
        getline(cin, s);
        stringstream sin(s);
        T v;
        while (sin >> v) add(v);
    }

    node* find(T x, node *v) {
        if (!v || v->val) return v;
        if (x < v->val) return find(x, v->left);
        else return find(x, v->right);
    }

    void inorder_(queue<T> &res, auto comp, node* v) {
        if (v) {
            inorder_(res, comp, v->left);
            if (comp(v)) res.push(v->val);
            inorder_(res, comp, v->right);
        }
    }
    queue<T> inorder(auto comp, node* v) {
        queue<T> res;
        inorder_(res, comp, v);
        return res;
    }

    int deep(node* v) {
        if (v) return max(deep(v->left), deep(v->right)) + 1;
        return 0;
    }
};


void solve1() {
    tree<int> tr;
    tr.input();
    queue<int> ans = tr.inorder([](auto v) {return v->left && !v->right; }, tr.root);

    cout << "Answer: " << ans.SIZE << '\n';
    if (!ans.empty()) 
        cout << "These are " << ans;
    else              
        cout << "No such vertexes";
    cout << '\n';
}

void solve2() {
    tree<int> tr;
    tr.input();
    cout << "Answer: " << tr.deep(tr.root) << '\n';
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
    cout << "Enter task numder: ";
    while (cin >> num && num > -1) {
        cin.get();
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
        cout << '\n';
        if (num > -1) 
            cout << "Enter task numder: ";
    }
}

