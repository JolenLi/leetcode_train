//
// Created by Jolen on 2021/6/25.
//

//
// Created by Jolen on 2021/6/24.
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


using namespace std;


int longestPalindromeSubseq(string s) {
    if (s.size() < 2)
        return s.size();
    vector<vector<int>> memo(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++)
        memo[i][i] = 1;
    for (int right = 0; right < s.size(); right++) {
        char c1 = s.at(right);
        for (int left = right-1; left>=0; left--) {
            char c2 = s.at(left);
            if (c1 == c2)
                memo[left][right] = memo[left + 1][right - 1] + 2;
            else {
                memo[left][right] = max(memo[left + 1][right], memo[left][right - 1]);
            }
        }
    }
    return memo[0][s.size() - 1];
}

int main() {
    string s = "cbbd";
    cout << longestPalindromeSubseq(s) << endl;
}