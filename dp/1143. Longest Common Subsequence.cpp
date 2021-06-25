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

int longestCommonSubsequence(string text1, string text2) {
    if(text1.empty()||text2.empty())
        return 0;
    vector<vector<int>> memo(text1.size()+1,vector<int>(text2.size()+1,0));
    int ans =0;
    for(int i =1;i<=text1.size();i++)
        for(int j=1;j<=text2.size();j++)
        {
            if(text1[i-1]==text2[j-1]){
                memo[i][j] = memo[i-1][j-1]+1;
                ans = max(ans,memo[i][j]);
            }else{
                memo[i][j] = max(memo[i-1][j-1],max(memo[i-1][j],memo[i][j-1]));
            }
        }
    return ans;
}

int main() {
    string text1 = "abc", text2 = "def";
    cout << longestCommonSubsequence(text1,text2) << endl;
}