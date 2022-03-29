

//
// Created by Jolen on 2021/6/24.
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

int update(vector<int> &nums, int l, int r) {
    return l + r >> 1;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int left = nums1.size() + nums2.size();
    if (left % 2)
        left = left >> 1;
    else
        left = left >> 1 - 1;

    int res = 0;
    int n1 = nums1.size(), n2 = nums2.size();
    int m1 = n1 >> 1, m2 = n2 >> 1;
    int l1 = 0, l2 = 0, r1 = n1, r2 = n2;
    while (res != left) {
        if (res < left) {
            if (m2 == n2 || nums1[m1] <= nums2[m2]) {
                res += (m1 - l1);
                l1 = m1 + 1;
                if (l1 > r1)
                    m1 = n1;
                else
                    m1 = (r1 + l1) / 2;
            } else if (m1 == n1 || nums1[m1] > nums2[m2]) {
                res += (m2 - l2);
                l2 = m2 + 1;
                if (l2 > r2)
                    m2 = n2;
                else
                    m2 = (r2 + l2) / 2;
            }
        } else {
            if (l2==0||nums1[m1] <= nums2[m2]) {
                res -= (l1/2);
            }
        }
    }
}



int main() {
    cout << mySqrt(9) << endl;
}