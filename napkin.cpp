//
// Created by zsr on 2022/6/5.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x7fffffff;
typedef long long ll;
int head[MAXN], tot, s, t, n, a[200][200];
struct node {
    int to, nxt, flow, cost;
} e[MAXN];
void add(int x, int y, int z, int c) {
    e[tot].to = y;
    e[tot].nxt = head[x];
    e[tot].flow = z;
    e[tot].cost = c;
    head[x] = tot++;
}
void add_edge(int x, int y, int z, int c) {
    add(x, y, z, c);
    add(y, x, 0, -c);
}
int dis[MAXN], q[MAXN], l, r, pre[MAXN], path[MAXN], visit[MAXN];
bool spfa() {
    for (int i = 0; i <= 2 * n + 1; i++) dis[i] = INF;
    for (int i = 0; i <= 2 * n + 1; i++) pre[i] = -1;
    l = 0, r = 0;
    dis[s] = 0;
    q[++r] = s;
    while (l != r) {
        int u = q[++l];
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].flow && dis[u] + e[i].cost < dis[v]) {
                dis[v] = dis[u] + e[i].cost;
                pre[v] = u, path[v] = i;
                if (!visit[v])
                    q[++r] = v, visit[v] = 1;
            }
        }
        visit[u] = 0;
    }
    if (pre[t] == -1)
        return false;
    return true;
}
int mcmf() {
    int f = 0, cost = 0;
    while (spfa()) {
        int min_f = INF;
        for (int i = t; i != s; i = pre[i]) {
            if (e[path[i]].flow < min_f)
                min_f = e[path[i]].flow;
        }
        f += min_f;
        cost += dis[t] * min_f;
        for (int i = t; i != s; i = pre[i]) {
            e[path[i]].flow -= min_f;
            e[path[i] ^ 1].flow += min_f;
        }
    }
    return cost;
}
int main() {
    int p, f_m, f_p, s_n, s_p;
    cin>>n>>p>>f_m>>f_p>>s_n>>s_p;
    memset(head, -1, sizeof(head));
    s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        int need;
        cin>>need;
        add_edge(s, i, need, 0);
        add_edge(i + n, t, need, 0);
    }
    for (int i = 1; i <= n; i++) {
        add_edge(s, i + n, INF, p);
    }
    for (int i = 1; i < n; i++)
        add_edge(i, i + 1, INF, 0);
    for (int i = 1; i + f_m <= n; i++)
        add_edge(i, i + f_m + n, INF, f_p);
    for (int i = 1; i + s_n <= n; i++)
        add_edge(i, i + n + s_n, INF, s_p);
    cout<<mcmf();
    return 0;
}