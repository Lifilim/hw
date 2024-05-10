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

    int depth(node* v) {
        if (v) return max(depth(v->left), depth(v->right)) + 1;
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
        cout << "No such vertices";
    cout << '\n';
}

void solve2() {
    tree<int> tr;
    tr.input();
    cout << "Answer: " << tr.depth(tr.root) << '\n';
}



template<typename T>
struct tree_AVL {
    struct node {
        T val;
        node* left = nullptr;
        node* right = nullptr;
    };
    node* root = nullptr;

    //////////////////////////////////////////////////

    void input_(node *&t, int n, queue<T> &q) {
        if (n <= 0) return;
        t = new node;
        t->val = q.pop();
        input_(t->left, n / 2, q);
        input_(t->right, n - n / 2 - 1, q);
    }

    void input() {
        string s;
        getline(cin, s);
        stringstream sin(s);
        queue<T> q;
        T v;
        while (sin >> v) q.push(v);
        input_(root, q.SIZE, q);
    }

    T sum_leaves(node* tr) {
        if (!tr->left && !tr->right)
            return tr->val;
        if (!tr->left && tr->right)
            return sum_leaves(tr->right);
        if (tr->left && !tr->right)
            return sum_leaves(tr->left);
        if (tr->left && tr->right)
            return sum_leaves(tr->left) + sum_leaves(tr->right);
    }

    void level_vertices_(node* tr, int k, queue<T> &q) {
        if (k == 1) return q.push(tr->val);
        if (tr->left) level_vertices_(tr->left, k - 1, q);
        if (tr->right) level_vertices_(tr->right, k - 1, q);
    }
    queue<T> level_vertices(int k) {
        assert(k > 0);
        queue<T> q;
        level_vertices_(root, k, q);
        return q;
    }

};


void solve3() {
    tree_AVL<int> tr;
    tr.input();
    cout << tr.sum_leaves(tr.root);
    cout << '\n';
}

void solve4() {
    tree_AVL<int> tr;
    tr.input();
    int k;
    cout << "Enter level k: ";
    cin >> k;
    cout << tr.level_vertices(k);
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
        case 2: // tree depth
            solve2();
            break;
        case 3: // leaves' sum
            solve3();
            break;
        case 4: // vertices of level k
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

