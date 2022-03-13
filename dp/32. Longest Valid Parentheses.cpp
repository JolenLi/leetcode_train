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
//// 左右两遍
//int longestValidParentheses(string s) {
//    int res = 0;
//    int open = 0, close = 0;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '(')
//            open++;
//        else if (s[i] == ')')
//            close++;
//        if (open == close)
//            res = max(res, open + close);
//        else if (open < close) {
//            open = close = 0;
//        }
//    }
//
//
//    open = 0, close = 0;
//    for (int i = s.size()-1; i >=0; i--) {
//        if (s[i] == '(')
//            open++;
//        else if (s[i] == ')')
//            close++;
//        if (open == close)
//            res = max(res, open + close);
//        else if (open > close) {
//            open = close = 0;
//        }
//    }
//
//    return res;
//}


//// dp

/****
if s[i] == '(' :
    dp[i] = 0
if s[i] == ')' :
    if s[i - 1] == '(' :
        dp[i] = dp[i - 2] + 2 #要保证i - 2 >= 0

if s[i - 1] == ')' and s[i - dp[i - 1] - 1] == '(' :
    dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 #要保证i - dp[i - 1] - 2 >= 0

****/
int longestValidParentheses(string s) {
    vector<int> dp(s.size(), 0);
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                if (i <= 2) dp[i] = 2;
                else dp[i] = dp[i - 2] + 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2;
                if (i - dp[i - 1] - 2 >= 0)
                    dp[i] += dp[i - dp[i - 1] - 2];
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    string s = "(()";
    cout << longestValidParentheses(s) << endl;
}