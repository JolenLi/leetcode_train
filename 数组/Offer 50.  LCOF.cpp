//
// Created by Jolen on 2021/6/22.
//

#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;
char firstUniqChar(string s) {
    unordered_map<char,int> charFreq;
    for(int i =0;i<s.size();i++)
        charFreq[s[i]]+=1;
    for(int i =0;i<s.size();i++)
        if(charFreq[s[i]]==1)
            return s[i];
    return ' ';
}
int main()
{
    string s = "leetcode";
    cout<<firstUniqChar(s);
}


