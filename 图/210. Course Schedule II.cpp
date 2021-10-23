//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;
bool hasCircus;
vector<vector<int>> edges;
vector<int> visited;
/// visted=0 未检查过
/// visted=1 正在检查
/// visted=2 查过但是恢复了

void dfs(int i) {
    if (visited[i] == 1 || hasCircus) {
        hasCircus = true;
        return;
    }
    visited[i] = 1;
    for (const auto &nextId:edges[i]) {
        if (visited[nextId] == 1 || hasCircus) {
            hasCircus = true;
            return;
        } else if (visited[nextId] == 0) {
            dfs(nextId);
        }
    }
    visited[i] = 2;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto &it:prerequisites) {
        edges[it[0]].push_back(it[1]);
    }
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i])
            dfs(i);
    }
    return !hasCircus;
}

vector<int>res;
void traverse(int i){
    visited[i] =1;
    for(const auto& next:edges[i]){
        if(!visited[next])
            traverse(next);
    }
    res.push_back(i);
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    if(!canFinish(numCourses,prerequisites))return res;
    visited = vector<int>(numCourses);
    for(int i =0;i<numCourses;i++){
        if(!visited[i])
            traverse(i);
    }
    return res;
}
int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    auto ans = findOrder(numCourses, prerequisites);
    for(auto i :ans)
        cout << i;
    cout<< endl;
}