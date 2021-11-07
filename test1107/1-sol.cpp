#include <bits/stdc++.h>
using namespace std;

inline int rd() {
    int i = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        i = (i << 1) + (i << 3) + ch - '0';
        ch = getchar();
    }
    return i * f;
}

const int N = 1e6 + 50;
int n, m, dfnum, bcc, ans, num = 1;
int h[N], dfn[N], low[N], sz[N];
bool f[N], used[N];

struct edge {
    int to, next;
} data[N << 1];

vector<int> a[N];
stack<int> qq;
stack<int> q;

inline void tarjan(int x) {
    dfn[x] = low[x] = ++dfnum;
    qq.push(x);
    for (int i = h[x]; i; i = data[i].next) {
        int y = data[i].to;
        if (used[i >> 1])
            continue;
        used[i >> 1] = 1;
        q.push(i >> 1);
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] < dfn[x])
                continue;
            ++bcc;
            while (1) {
                int z = qq.top();
                qq.pop();
                sz[bcc]++;
                if (z == y)
                    break;
            }
            sz[bcc]++;
            while (1) {
                int j = q.top();
                q.pop();
                a[bcc].push_back(j);
                if (j == (i >> 1))
                    break;
            }
        }
        low[x] = min(low[x], dfn[y]);
    }
}
int main() {
    // freopen("graph.in", "r", stdin);
    // freopen("graph.out", "w", stdout);
    n = rd(), m = rd();
    for (int i = 1; i <= m; ++i) {
        int x = rd(), y = rd();
        data[++num].to = y;
        data[num].next = h[x];
        h[x] = num;
        data[++num].to = x;
        data[num].next = h[y];
        h[y] = num;
    }
    tarjan(1);
    for (int i = 1; i <= bcc; ++i) {
        if (sz[i] != a[i].size())
            continue;
        for (int j = 0; j < a[i].size(); ++j) f[a[i][j]] = 1;
    }
    for (int i = 1; i <= m; ++i)
        if (f[i])
            ans ^= i;
    cout << ans << '\n';
}