//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
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



int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++)
        memo[i][0] = i;
    for (int i = 0; i <= word2.size(); i++)
        memo[0][i] = i;

    for (int i = 1;i<=word1.size();i++)
        for(int j = 1;j<=word2.size();j++)
        {
            if(word1[i-1]==word2[j-1])
            {
                memo[i][j] = memo[i-1][j-1];
            }else{
                memo[i][j] = min(memo[i-1][j],memo[i][j-1],memo[i-1][j-1])+1;
            }
        }
        for(auto i:memo)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return memo[word1.size()][word2.size()];

}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2);
}