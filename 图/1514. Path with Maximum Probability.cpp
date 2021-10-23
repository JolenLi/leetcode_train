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

double disTo(vector<vector<pair<double,int>>> graph, int start, int end) {
    int V = graph.size();
    vector<double> disTo(V, 0);
    disTo[start] = 1;

    priority_queue<pair<double,int>> pq;
    pq.push({1,start});
    while(!pq.empty()){
        auto [prob, to] = pq.top();
        pq.pop();
        if(prob<disTo[to]){
            continue;
        }
        for(auto [pNext,nodeNext]:graph[to]){
            double dis = disTo[to]*pNext;
            if(disTo[nodeNext]<dis){
                disTo[nodeNext] = dis;
                pq.push({dis,nodeNext});
            }
        }
        if(to==end)
            return disTo[end];
    }
    return 0;
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end) {
    vector<vector<pair<double,int>>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        auto &e = edges[i];
        graph[e[1]].push_back({succProb[i],e[0]});
        graph[e[0]].push_back({succProb[i],e[1]});
    }
    return disTo(graph, start, end);
}
int main() {
    vector<vector<int>> times = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
    vector<double> prob={0.37,0.17,0.93,0.23,0.39,0.04};
    int n = 3, k = 4;
    cout << maxProbability(times.size(),times,prob, n, k) << endl;
}