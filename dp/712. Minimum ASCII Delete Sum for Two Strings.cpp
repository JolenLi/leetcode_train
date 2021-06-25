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

int minimumDeleteSum(string word1, string word2) {
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); i++){
        memo[i][0] = memo[i-1][0]+word1.at(i-1);
    }

    for (int i = 1; i <= word2.size(); i++)
        memo[0][i] = memo[0][i-1]+word2.at(i-1);
    for(int i =1;i<=word1.size();i++){
        char c1 = word1.at(i-1);
        for(int j=1;j<=word2.size();j++)
        {
            char c2 = word2.at(j-1);
            if(c1==c2){
                memo[i][j]=memo[i-1][j-1];
            }else{
                memo[i][j]=min(memo[i-1][j]+word1.at(i-1),memo[i][j-1]+word2.at(j-1));
            }
        }
    }
//    for(auto i:memo)
//    {
//        for(int j:i)
//            cout<<j<<" ";
//        cout<<endl;
//    }
    return memo[word1.size()][word2.size()];

}

int main() {
    string text1 = "delete", text2 = "leet";
    cout << minimumDeleteSum(text1,text2) << endl;
}