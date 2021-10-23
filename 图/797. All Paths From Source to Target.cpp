//
// Created by Jolen on 2021/10/23.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> path;
void dfs(vector<vector<int>>& graph,int i){
    path.push_back(i);
    if(i==graph.size()-1){
        res.push_back(path);
        path.pop_back();
        return;
    }
    for(auto to:graph[i]){
        dfs(graph,to);
    }
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dfs(graph,0);
    return res;
}