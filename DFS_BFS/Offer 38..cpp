//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
vector<string> ans;

void dfs(string s,int x){
    if(x==s.size()-1)
        ans.push_back(s);

    set<char> temp;
    for(int i=x;i<s.size();i++)
    {
        if(temp.find(s[i])==temp.end())
        {
            temp.insert(s[i]);
            swap(s[i],s[x]);
            dfs(s,x+1);
            swap(s[i],s[x]);
        }
    }
}
vector<string> permutation(string s) {
    sort(s.begin(),s.end());
    dfs(s,0);
    return ans;
}

int main()
{
    auto ans = permutation("aab");
    for(auto i:ans)
        cout<<i<<endl;
}