#include <bits/stdc++.h>

using LL = long long;

const int MAXN = 1e5 + 5;

struct SplayTree {
    struct Node {
        Node *fa, *ch[2];
        LL sum, tag, val;
        int size;
        
        Node(LL _val): sum(_val), val(_val) {
            fa = ch[0] = ch[1] = 0;
            tag = 0;
            size = 1;
        }
        
        void Add(LL w) {
            val += w;
            sum += w * size;
            tag += w;
        }
        
        void Down() {
            for (int i = 0; i < 2; ++i) if (ch[i])
                ch[i]->Add(tag);
            tag = 0;
        }
        
        void DownR() {
            if (fa) fa->DownR();
            Down();
        }
        
        void Update() {
            sum = val;
            size = 1;
            for (int i = 0; i < 2; ++i) if (ch[i]) {
                sum += ch[i]->sum;
                size += ch[i]->size;
            }
        }
        
        int Which() {
            return this == fa->ch[1];
        }
    } *root;
    
    SplayTree() = default;
    
    void Rotate(Node *k) {
        Node *p = k->fa;
        int l = k->Which(), r = l ^ 1;
        
        k->fa = p->fa;
        if (p->fa) p->fa->ch[p->Which()] = k;
        
        p->ch[l] = k->ch[r];
        if (k->ch[r]) k->ch[r]->fa = p;
        
        k->ch[r] = p;
        p->fa = k;
        
        p->Update();
        k->Update();
    }
    
    void Splay(Node *k, Node *aim_fa = 0) {
        k->DownR();
        
        while (k->fa != aim_fa) {
            Node *p = k->fa;
            if (p->fa != aim_fa) {
                if (k->Which() ^ p->Which()) Rotate(k);
                else Rotate(p);
            }
            Rotate(k);
        }
        
        if (!aim_fa) root = k;
    }
    
    void Insert(LL val, Node *&k, Node *fa = 0) {
        if (!k) {
            k = new Node(val);
            k->fa = fa;
            Splay(k);
            return;
        }
        k->Down();
        Insert(val, k->ch[val > k->val], k);
    }
    
    void Add(LL val) {
        root->Add(val);
    }
    
    void Traverse(std::vector<LL> &vec, Node *k) {
        if (!k) return;
        k->Down();
        Traverse(vec, k->ch[0]);
        vec.push_back(k->val);
        Traverse(vec, k->ch[1]);
    }
    
    void Delete(Node *&k) {
        if (!k) return;
        for (int i = 0; i < 2; ++i) Delete(k->ch[i]);
        delete k; k = 0;
    }
    
    void Merge(SplayTree &oth) {
        if (root->size < oth.root->size) std::swap(root, oth.root);
        
        // std::cerr << root->size << " " << oth.root->size << std::endl;
        
        std::vector<LL> list;
        oth.Traverse(list, oth.root);
        oth.Delete(oth.root);
        for (LL i: list)
            Insert(i, root);
    }
    
    LL Query(LL val) {
        Node *k = root, *p = 0;
        while (k) {
            k->Down();
            if (k->val < val) {
                p = k;
                k = k->ch[1];
            } else {
                k = k->ch[0];
            }
        }
        if (!p) return root->sum;
        Splay(p);
        if (!root->ch[1]) {
            return 0;
        } else {
            return root->ch[1]->sum;
        }
    }
} splay[MAXN];

int n, q;
std::vector<int> G[MAXN];
int fa[MAXN], w[MAXN];

std::vector<std::pair<int, int>> qry[MAXN];

LL ans[MAXN];

void DFS(int now) {
    splay[now].Insert(0, splay[now].root);
    for (int to: G[now]) {
        DFS(to);
        
        splay[to].Add(w[to]);
        splay[now].Merge(splay[to]);
    }
    
    for (auto i: qry[now]) {
        int k = i.first, idx = i.second;
        
        ans[idx] = splay[now].Query(k);
    }
}

int main() {
    
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d%d", fa + i, w + i);
        G[fa[i]].push_back(i);
    }
    
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        static int u, k;
        
        scanf("%d%d", &u, &k);
        qry[u].emplace_back(k, i);
    }
    
    DFS(1);
    
    for (int i = 1; i <= q; ++i)
        printf("%lld\n", ans[i]);
    
    return 0;
}