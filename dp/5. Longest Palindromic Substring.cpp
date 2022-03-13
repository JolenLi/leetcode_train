//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>

using namespace std;
////  dp
//string longestPalindrome(string s) {
//    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//    for (int i = 0; i < s.size(); i++)
//        dp[i][i] = 1;
//    int start = 0, end = 0;
//    for (int r = 1; r < s.size(); r++) {
//        for (int i = 0; i < r; i++) {
//            if (s[r] == s[i] && (r - i <= 2 || dp[i + 1][r - 1])) {
//                dp[i][r] = true;
//                if (end - start < r - i) {
//                    start = i;
//                    end = r;
//                }
//            }
//        }
//    }
//    return s.substr(start, end - start + 1);
//}


//// 中心扩散

pair<int, int> expand(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return {left + 1, right - 1};
}

string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 1; i < s.size(); i++) {
        pair<int, int> range1 = expand(s, i, i);
        pair<int, int> range2 = expand(s, i - 1, i);
        if (range1.second - range1.first > end - start) {
            start = range1.first;
            end = range1.second;
        }
        if (range2.second - range2.first > end - start) {
            start = range2.first;
            end = range2.second;
        }
    }
    return s.substr(start, end - start + 1);
}

int main() {
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
}