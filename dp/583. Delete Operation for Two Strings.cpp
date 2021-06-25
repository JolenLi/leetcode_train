//
// Created by Jolen on 2021/6/24.
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

int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++)
        memo[i][0] = i;
    for (int i = 0; i <= word2.size(); i++)
        memo[0][i] = i;
    for(int i =1;i<=word1.size();i++){
        char c1 = word1.at(i-1);
        for(int j=1;j<=word2.size();j++)
        {
            char c2 = word2.at(j-1);
            if(c1==c2){
                memo[i][j]=memo[i-1][j-1];
            }else{
                memo[i][j]=min(memo[i-1][j],memo[i][j-1])+1;
            }
        }
    }
    for(auto i:memo)
    {
        for(int j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return memo[word1.size()][word2.size()];

}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << minDistance(word1, word2) << endl;
}