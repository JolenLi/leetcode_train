//
// Created by Jolen on 2021/6/26.
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

#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

string convertToTitle(int columnNumber) {
    string str = "";
    while (columnNumber) {
        columnNumber--;
        int res = columnNumber%26;
        columnNumber/=26;
        str+=('A'+res);
    }
    reverse(str.begin(),str.end());
    return str;
}

int main() {
    cout << convertToTitle(27) << endl;
}

