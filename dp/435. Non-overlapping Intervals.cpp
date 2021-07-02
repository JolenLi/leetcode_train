//
// Created by Jolen on 2021/7/2.
//

//
// Created by Jolen on 2021/7/1.
//
//// sort


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;
////   dp
//int eraseOverlapIntervals(vector<vector<int>> &intervals) {
//
//    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
//        return a[1] < b[1];
//    });
//
//    vector<int> memo(intervals.size(), 1);
//    for (int i = 1; i < intervals.size(); i++)
//        for (int j = 0; j < i; j++) {
//            if (intervals[i][0] >= intervals[j][1])
//                memo[i] = max(memo[i], memo[j] + 1);
//        }
//
//    return intervals.size()-*max_element(memo.begin(),memo.end());
//}


////   贪心
int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
        return a[1] < b[1];
    });

    int cnt=1,end = intervals[0][1];
    for(int i =1;i<intervals.size();i++){
        if(intervals[i][0]>=end){
            end = intervals[i][1];
            cnt++;
        }
    }
    return intervals.size()-cnt;
}


int main() {
    vector<vector<int>> intervals = {{1,  2},
                                     {2, 3},
                                     {3,  4},
                                     {1,  3}};
    cout << eraseOverlapIntervals(intervals);

}