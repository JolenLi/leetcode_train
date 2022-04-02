//
// Created by Jolen on 2022/4/2.
//

//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;
//// dfs
//vector<int> pointColor;
//const int RED = 1;
//const int BLUE = -1;
//
//bool dfs(vector<vector<int>> &graph, int point, int color) {
//    if (pointColor[point] == color)
//        return true;
//    else if (pointColor[point] == -color)
//        return false;
//    else if (pointColor[point] == 0) {
//        pointColor[point] = color;
//        for (const int &next:graph[point]) {
//            if (!dfs(graph, next, -color))
//                return false;
//        }
//    }
//    return true;
//}
//
//bool isBipartite(vector<vector<int>> &graph) {
//    int n = graph.size();
//    pointColor.resize(n);
//    for (int i = 0; i < n; i++) {
//        if (pointColor[i] == 0 && !dfs(graph, i, RED))
//            return false;
//    }
//    return true;
//}

////   BFS
vector<int> pointColor;
const int RED = 1;
const int BLUE = -1;


bool bfs(vector<vector<int>> &graph, int point) {
    int color = RED;
    pointColor[point] = color;
    queue<int> points;
    points.push(point);
    while (!points.empty()) {
        int cur = points.front();
        points.pop();
        color = -pointColor[cur];
        for (const int &next:graph[cur]) {
            if (pointColor[next] == 0) {
                pointColor[next] = color;
                points.push(next);
            } else if (pointColor[next] != color) {
                return false;
            } else
                continue;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    pointColor.resize(n);
    for (int i = 0; i < n; i++) {
        if (pointColor[i] == 0 && !bfs(graph, i))
            return false;
    }
    return true;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto ans = isBipartite(prerequisites);
    cout << ans << endl;
}