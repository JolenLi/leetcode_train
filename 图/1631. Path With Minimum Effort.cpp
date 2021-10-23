//
// Created by Jolen on 2021/10/23.
//


#include <bits/stdc++.h>
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
    int x, y, dis;

    State(int a, int b, int c) : x(a), y(b), dis(c) {}

    bool operator<(State state) const {        // 根据 dis 从小到大排序
        return dis > state.dis;
    }
};

vector<vector<int>> dirs = {{0,  1},
                            {1,  0},
                            {0,  -1},
                            {-1, 0}};

vector<vector<int>> getAdj(vector<vector<int>> &graph, int x, int y) {
    int m = graph.size(), n = graph[0].size();
    // 存储相邻节点
    vector<vector<int>> neighbors;
    for (vector<int> dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= m || nx < 0 || ny >= n || ny < 0) {// 索引越界
            continue;
        }
        neighbors.push_back({nx, ny});
    }
    return neighbors;
}

int dijkstra(vector<vector<int>> &graph) {
    int endX = graph.size() - 1, endY = graph[0].size() - 1;
    int V = graph.size();
    int inf = INT_MAX / 2;

    vector<vector<int>> distTo(V, vector<int>(V, inf));

    distTo[0][0] = 0;

    priority_queue<State> pq;
    pq.push(State(0, 0, 0));

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        int curX = cur.x, curY = cur.y, curCost = cur.dis;
        if (curX == endX && curY == endY)
            return curCost;
        if (curCost > distTo[curX][curY])
            continue;

        for (auto next : getAdj(graph, curX, curY)) {
            int nextX = next[0], nextY = next[1];
            int costMax = max(curCost, abs(graph[curX][curY] - graph[nextX][nextY]));
            if (costMax < distTo[nextX][nextY]) {
                distTo[nextX][nextY] = costMax;
                pq.push({nextX, nextY, costMax});
            }
        }
    }
    return -1;
}


int minimumEffortPath(vector<vector<int>> &heights) {
    return dijkstra(heights);
}

int main() {
    vector<vector<int>> heights = {{1, 2, 2},
                                   {3, 8, 2},
                                   {5, 3, 5}};
    cout << minimumEffortPath(heights) << endl;
}