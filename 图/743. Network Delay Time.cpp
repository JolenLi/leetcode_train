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

vector<int> dijkstra(int start, vector<vector<int>> graph) {
    int V = graph.size();
    int inf = INT_MAX / 2;

    vector<bool> vis(V, 0);
    vector<int> distTo(V, inf);
    distTo[start] = 0;

    for (int i = 1; i < V; i++) { //for v point
        int to = 0;
        for (int j = 1; j < V; j++) {
            if (!vis[j] && distTo[j] < distTo[to])
                to = j;
        }
        vis[to] = 1;
        for (int j = 1; j < V; j++)
            distTo[j] = min(distTo[j],distTo[to]+graph[to][j]);
    }
    return distTo;
}
//
//vector<int> dijkstra(int start, vector<vector<int>> graph) {
//    int V = graph.size();
//    int inf = INT_MAX / 2;
//
//    vector<bool> vis(V, 0);
//    vector<int> distTo(V, inf);
//    distTo[start] = 0;
//
//    priority_queue<State> pq;
//    pq.push(State(start, 0));
//
//    while (!pq.empty()) {
//        State cur = pq.top();
//        pq.pop();
//        if (vis[cur.id])
//            continue;
//        for (int nextID = 1; nextID < V; nextID++) {
//            int disNext = distTo[cur.id] + graph[cur.id][nextID];
//            if (distTo[nextID] > disNext) {
//                distTo[nextID] = disNext;
//                pq.push(State(nextID, disNext));
//            }
//            vis[cur.id] = true;
//        }
//    }
//    return distTo;
//}

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // 节点编号是从 1 开始的，所以要一个大小为 n + 1 的邻接表
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX / 2));

    for (vector<int> edge : times) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        graph[from][to] = weight;
    }
    vector<int> distTo = dijkstra(k, graph);

    int res = 0;
    for (int i = 1; i < distTo.size(); i++)
        res = max(res, distTo[i]);
    return res == (INT_MAX / 2) ? -1 : res;
}


int main() {
    vector<vector<int>> times = {{2, 1, 1},
                                 {2, 3, 1},
                                 {3, 4, 1}};
    int n = 4, k = 2;
    cout << networkDelayTime(times, n, k) << endl;
}