//
// Created by Jolen on 2021/6/26.
//




//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

#include <cstring>
#include <string>

using namespace std;

//
//int numDecodings(string s) {
//    vector<int> dp(s.size() + 1, 0);
//    if (s[0] == '0')return 0;
//    dp[0] = 1, dp[1] = 1;
//    for (int i = 1; i < s.size(); i++) {
//        if (s[i] == '0') {
//            if (s[i - 1] > '0' && s[i - 1] <= '2')
//                dp[i + 1] = dp[i - 1];
//            else
//                return 0;
//        } else if (s[i - 1] == '0')
//            dp[i + 1] = dp[i];
//        else if (s[i - 1] == '1')
//            dp[i + 1] = dp[i] + dp[i - 1];
//        else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
//            dp[i + 1] = dp[i] + dp[i - 1];
//        } else
//            dp[i + 1] = dp[i];
//    }
//    return dp[s.size()];
//}



int numDecodings(string s) {
    vector<int> dp(s.size() + 1, 0);
    if (s[0] == '0')return 0;
    dp[0] = 1, dp[1] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '0')
            dp[i + 1] += dp[i];
        if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26)
            dp[i + 1] += dp[i - 1];
    }
    return dp[s.size()];
}

int main() {
    string s = "2026";
    cout << numDecodings(s) << endl;
}

