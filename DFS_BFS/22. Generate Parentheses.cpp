

//
// Created by Jolen on 2022/3/11.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<string> res;

void backTrack(string str,int in, int out,int n){
    if(in==out&&in ==n){
        res.push_back(str);
        return;
    }
    if(in<n){
        str.push_back('(');
        backTrack(str,in+1,out,n);
        str.pop_back();
    }
    if(out<in){
        str.push_back(')');
        backTrack(str,in,out+1,n);
        str.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    backTrack("",0,0,n);
    return res;
}

int main() {
    auto s = generateParenthesis(3);
    for(auto i:s)
        cout<<i<<endl;
}