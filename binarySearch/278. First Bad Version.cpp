//
// Created by Jolen on 2021/6/25.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left >> 1);
            if (isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};