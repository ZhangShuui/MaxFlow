//
// Created by zsr on 2022/6/5.
//

#include<iostream>
#include<limits>
#include<iomanip>
using namespace std;
struct Point{
    char ch;//节点标识
    int e;//存货量
    int h;//高度
};
Point point[6];
int graph[6][6]={{0,10,10,0,0,0},
                 {0,0,2,8,4,0},
                 {0,0,0,9,0,0},
                 {0,0,0,0,9,10},
                 {0,0,0,0,0,10},
                 {0,0,0,0,0,0}} ;
int Push_Relabel(int s, int t,int n); //参数为 起点  端点  节点数

int main(){
    int  n=6;
    point[0].ch='s';  point[0].e=0; point[0].h=0;
    point[1].ch='u';  point[1].e=0; point[1].h=0;
    point[2].ch='v';  point[2].e=0; point[2].h=0;
    point[3].ch='a';  point[3].e=0; point[3].h=0;
    point[4].ch='b';  point[4].e=0; point[4].h=0;
    point[5].ch='t';  point[5].e=0; point[5].h=0;
    cout<<"原始网络图邻接矩阵："<<endl;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            cout<<setw(6)<<graph[i][j]<<" ";

        }cout<<endl;
    }
    cout<<"max_flow="<<Push_Relabel(0, n-1,n)<<endl;
    cout<<"graph流图矩阵："<<endl;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            cout<<setw(6)<<graph[i][j]<<" ";

        }cout<<endl;
    }
    return 0;
}

int Push_Relabel(int s, int t,int n)
{
    int  max_flow;
    point[s].h = n;  //起始点高度置为n 最高
    //初始化 将start点的库存 流出去 update剩余图
    for (int u = 1; u <= t; u++) {
        if (graph[s][u] > 0) {
            point[u].e = graph[s][u];
            point[s].e -= graph[s][u];
            graph[u][s] = graph[s][u];
            graph[s][u] = 0;
        }
    }
    while(1) {
        int finishflag = 1;
        for (int u = s+1; u < t; u++) {  //搜索除节点s 节点t以外的节点
            if (point[u].e > 0) {  //发现库存量大于0的节点 u
                finishflag = 0;
                int relabel = 1;   //先假设顶点u需要relabel ,提高高度h
                for (int v = s; v <= t && point[u].e > 0; v++) {   //搜索能push的顶点
                    if (graph[u][v] > 0 && point[u].h >point[v].h) {
                        relabel = 0;
                        int bottleneck = min(graph[u][v], point[u].e);
                        point[u].e -= bottleneck;
                        point[v].e += bottleneck;
                        graph[u][v] -= bottleneck;
                        graph[v][u] += bottleneck;

                    }
                }
                if (relabel==1) {  //没有可以push的顶点,u节点需要relabel 提高高度
                    point[u].h += 1;
                }
            }
        }
        if (finishflag==1) { // 除源点和汇点外,每个顶点的e[i]都为0
            max_flow = 0;
            for (int u = s; u <= t; u++) {
                if (graph[t][u] > 0) {
                    max_flow += graph[t][u];
                }
            }
//            cout<<"max_flow="<<max_flow<<endl;
            break;
        }
    }
    return max_flow;
}
