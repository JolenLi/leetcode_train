
//
// Created by Jolen on 2022/3/29.
//

//
// Created by Jolen on 2021/6/25.
//



//
// Created by Jolen on 2021/6/24.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

bool isDigit(string str) {
    for (char c:str)
        if (!isdigit(c))
            return false;
    return true;
}
vector<int> cal(vector<int>& A,vector<int>&B,char oper){
    vector<int> res;
    for(int &a:A)
        for(int &b:B){
            if(oper=='+')
                res.push_back(a+b);
            else if(oper=='-')
                res.push_back(a-b);
            else if(oper=='*')
                res.push_back(a*b);
            else if(oper=='/')
                res.push_back(a/b);
        }
    return res;
}
vector<int> dfs(string str) {
    if(isDigit(str))
        return {stoi(str)};

    vector<int> ansA,ansB,res,ansAll;
    for(int i =0;i<str.size();i++){
        if(!isdigit(str[i])){
            ansA = dfs(str.substr(0,i));
            ansB = dfs(str.substr(i+1,str.size()-i-1));
            res = cal(ansA,ansB,str[i]);
            for(auto x:res)
                ansAll.push_back(x);
        }
    }
    return ansAll;
}

vector<int> diffWaysToCompute(string expression) {
    return dfs(expression);
}

int main() {
    string Str = "2-1-1*3-4*5";
    auto sss = diffWaysToCompute(Str);
    for(auto s:sss)
        cout<<s<<" ";
    cout<<endl;
//    cout << << endl;
}