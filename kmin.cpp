//
// Created by Jolen on 2021/6/25.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int deleteVector(vector<int> &A, int lo, int hi) {
    int mins = 1000000005, maxs = -1000000004;
//    if (hi > A.size() - 1)return 2000000005;
    for (int i = 0; i < A.size(); i++) {
        if (i < lo || i > hi) {
            mins = min(mins, A[i]);
            maxs = max(maxs, A[i]);
        }
    }
    return maxs - mins;
}

int solution(vector<int> &A, int K) {
    int n = A.size() - 1;
    int res = 1000000005;
    for (int i = 0; i <= n - K + 1; i++) {
//        cout<<i<<" "<<i+K-1<<" "<<deleteVector(A,i,i+K-1)<<endl;
        res = min(res, deleteVector(A, i, i + K - 1));
    }
    return res;
}


int main() {
    vector<int> nums = {5, 3, 6, 1, 3};
    cout << solution(nums, 2) << endl;
}