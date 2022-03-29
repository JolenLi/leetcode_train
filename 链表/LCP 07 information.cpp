
//
// Created by Jolen on 2021/7/1.
//

///// dp,dfs,bfs

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

//// dp
//int numWays(int n, vector<vector<int>> &relation, int k) {
//    vector<vector<int>> memo(k+1, vector<int>(n, 0));
//    memo[0][0] = 1;
//    for (int i = 1; i <= k; i++) {
//         for(auto it:relation){
//             memo[i][it[1]] += memo[i-1][it[0]];
//         }
//    }
//    return memo[k][n-1];
//}

//// bfs
//int numWays(int n, vector<vector<int>> &relation, int k) {
//    vector<vector<int>> trans(n);
//    for (auto &it:relation) {
//        trans[it[0]].push_back(it[1]);
//    }
//    queue<int> que;
//    que.push(0);
//    for (int i = 0; i < k; i++) {
//        int len = que.size();
//        for (int j = 0; j < len; j++) {
//            vector<int> next = trans[que.front()];
//            que.pop();
//            for (auto &it:next)
//                que.push(it);
//        }
//    }
//    int cnt  =0;
//    while(!que.empty()){
//        if(que.front()==n-1)
//            cnt++;
//        que.pop();
//    }
//    return cnt;
//}


int main() {
//    int n = 5, k = 3;
//    vector<vector<int>> relation = {{0, 2},
//                                    {2, 1},
//                                    {3, 4},
//                                    {2, 3},
//                                    {1, 4},
//                                    {2, 0},
//                                    {0, 4}};
//
//    cout << numWays(n, relation, k);
int num = 1;
    for(int i=1;i<=1500;){
        if(num%2==0||num%3==0||num%5==0)
            i++;
        num++;
    }
    cout<<num<<endl;
}