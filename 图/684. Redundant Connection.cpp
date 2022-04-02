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

vector<int> parent;

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    parent.resize(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (vector<int> &edge:edges) {
        int headA = find(edge[0]),headB=find(edge[1]);
        if(headA==headB)
            return edge;
        else
            parent[headA] = headB;
    }
    return {-1,-1};
}


int main() {

}