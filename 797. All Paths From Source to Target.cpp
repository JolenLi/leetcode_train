//
// Created by Jolen on 2021/6/23.
//

//// 图

#include<vector>
#include<iostream>
#include<queue>

using namespace std;


vector<vector<int>> res;

void traverse(const vector<vector<int>> &gragh, int start, vector<int> &path) {
    path.push_back(start);
    int size = gragh.size() - 1;
    if (start == size) {
        res.push_back(path);
        path.pop_back();
        return;
    }
    for (int it:gragh[start])
        traverse(gragh, it, path);
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> path;
    traverse(graph, 0, path);
    return res;
}

int main() {
    vector<vector<int>> graph = {{1},
                                 {}};
    allPathsSourceTarget(graph);
    for (auto i:res) {
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
}