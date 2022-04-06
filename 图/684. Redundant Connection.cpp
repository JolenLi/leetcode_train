//
// Created by Jolen on 2022/4/2.
//

//
// Created by Jolen on 2022/4/2.
//

//
// Created by Jolen on 2021/10/23.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> root;

int find(int child) {
    while (root[child] == child)
        child = root[child];
    return child;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    root.resize(n + 1);
    for (int i = 0; i <= n; i++)
        root[i] = i;

    for (auto &edge:edges) {
        int nodeA = find(edge[0]), nodeB = find(edge[1]);
        if (nodeA == nodeB)return edge;
        root[nodeA] = nodeB;
    }
    return {-1, -1};
}

int main() {

}