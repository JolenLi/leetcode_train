//
// Created by Jolen on 2021/10/23.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include <vector>

using namespace std;

struct State {
    int id, dis;

    State(int a, int b) : id(a), dis(b) {}

    bool operator<(State state) const {        // 根据 dis 从小到大排序
        return dis > state.dis;
    }
};

vector<int> dijkstra( vector<vector<pair<int,int>>> graph,int start) {
    int V = graph.size();
    int inf = INT_MAX / 2;

    vector<int> distTo(V, inf);    //创建距离矩阵
    distTo[start] = 0;

    priority_queue<State> pq;       //优先队列
    pq.push(State(start, 0));

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        int curId = cur.id, curDis = cur.dis;
        if (curDis > distTo[curId])
            continue;    //优先队列存的路径不是最近的，直接跳过
        for (auto [nextId,nextDis]:graph[curId]) { // 遍历所有路径
            int disNext = distTo[cur.id] + nextDis;
            if (distTo[nextId] > disNext) { //新路径比原来路径近
                distTo[nextId] = disNext;
                pq.push(State(nextId, disNext));
            }
        }
    }
    return distTo;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // 节点编号是从 1 开始的，所以要一个大小为 n + 1 的邻接表
//    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX / 2));
    vector<vector<pair<int,int>>> graph(n+1);
    for (vector<int> edge : times) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        graph[from].push_back({to,weight});
    }
    vector<int> distTo = dijkstra(graph,k);

    int res = 0;
    for (int i = 1; i < distTo.size(); i++)
        res = max(res, distTo[i]);
    return res == (INT_MAX / 2) ? -1 : res;
}
