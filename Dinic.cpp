//
// Created by zsr on 2022/6/5.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <deque>
#include <string.h>
using namespace std;
#define INFINITE 999999999
int G[300][300];
bool Visited[300];
int Layer[300]; int n,m;
bool CountLayer() {
    int layer = 0; deque<int>q;
    memset(Layer,0xff,sizeof(Layer));
    Layer[1] = 0; q.push_back(1);
    while( ! q.empty()) {
        int v = q.front();
        q.pop_front();
        for( int j = 1; j <= m; j ++ ) {
            if( G[v][j] > 0 && Layer[j] == -1 ) {
                Layer[j] = Layer[v] + 1;
                if( j == m )
                    return true;
                else
                    q.push_back(j);
            }
        }
    }
    return false;
}

int Dinic()
{
    int i; int s;
    int nMaxFlow = 0;
    deque<int> q;
    while( CountLayer() ) {
        q.push_back(1); //源点入栈
        memset(Visited,0,sizeof(Visited)); Visited[1] = 1;
        while( !q.empty()) {
            int nd = q.back();
            if( nd == m ) {//m为汇点
                int nMinC = INFINITE;
                int nMinC_vs; //容量最小边的起点
                for( i = 1;i < q.size(); i ++ ) {
                    int vs = q[i-1];
                    int ve = q[i];
                    if( G[vs][ve] > 0 ) {
                        if( nMinC > G[vs][ve] ) {
                            nMinC = G[vs][ve];
                            nMinC_vs = vs;
                        }
                    }
                }
                nMaxFlow += nMinC;
                for( i = 1;i < q.size(); i ++ ) {
                    int vs = q[i-1];
                    int ve = q[i];
                    G[vs][ve] -= nMinC;
                    G[ve][vs] += nMinC;
                }
                            //退栈到 nMinC_vs成为栈顶，以便继续dfs
                while( !q.empty() && q.back() != nMinC_vs ) {
                    Visited[q.back()] = 0;
                    q.pop_back();
                }
            }
            else {
                for( i = 1;i <= m; i ++ ) {
                    if( G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 &&
                        ! Visited[i]) {//只往下一层的没有走过的节点搜索
                        Visited[i] = 1;
                        q.push_back(i);
                        break;
                    }
                }
                if( i > m)
                    q.pop_back(); //如果找不到下一个点就回溯
            }
        }
    }
    return nMaxFlow;
}
int main()
{
    while (cin >> n >> m ) {
        int i,j,k;
        int s,e,c;
        memset( G,0,sizeof(G));
        for( i = 0;i < n;i ++ ) {
            cin >> s >> e >> c;
            G[s][e] += c; //两点之间可能有多条边
        }
        cout << Dinic() << endl;
    }
    return 0;
}