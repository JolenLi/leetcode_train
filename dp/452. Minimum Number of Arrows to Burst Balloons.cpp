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

int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
        return a[1] < b[1];
    });
    int cnt = 1, end = points[0][1];
    for (auto &point : points)
        if (point[0] > end) {
            end = point[1];
            cnt++;
        }

    return cnt;
}


int main() {
    vector<vector<int>> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {1, 3}};
    cout << findMinArrowShots(intervals);

}