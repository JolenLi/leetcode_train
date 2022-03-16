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


string add2Num(string num1, string num2) {
    string ans = "";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int add = 0;
    for (int i = 0; i < max(num1.size(), num2.size()); i++) {
        if (i < num1.size())
            add += num1[i] - '0';
        if (i < num2.size())
            add += num2[i] - '0';
        ans += to_string(add % 10);
        add /= 10;
    }
    if (add)
        ans += to_string(add);
    reverse(ans.begin(), ans.end());
    return ans;
}

int getNum(char &c) {
    return c - '0';
}

string multiply(string num1, string num2) {
    if(num1[0]=='0'||num2[0]=='0')return "0";
    string ans = "0";
    for (int i = num1.size() - 1; i >= 0; i--) {
        int add=0;
        string multAns = "";
        for (int j = num2.size() - 1; j >= 0; j--) {
            add = add + getNum(num1[i]) * getNum(num2[j]);
            multAns = to_string(add % 10) + multAns;
            add = add / 10;
        }
        if (add)
            multAns = to_string(add) + multAns;
        for (int k = num1.size() - 1; k > i; k--)
            multAns += "0";
        ans = add2Num(ans, multAns);
    }
    return ans;
}

int main() {
    string s1 = "0", s2 = "456";
    cout << multiply(s1, s2) << endl;
}