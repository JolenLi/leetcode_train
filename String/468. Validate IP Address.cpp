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
using namespace std;

vector<string> split(string str,char target){
    vector<string> res;
    int l=0;
    for(int r=0;r<str.size();r++)
        if(str[r]==target){
            res.push_back(str.substr(l,r-l));
            l = r+1;
        }
    res.push_back(str.substr(l,str.size()-l));
    return res;
}
string isIPV4(string query) {
    vector<string> numStr = split(query,'.');
    if (numStr.size() != 4)
        return "Neither";
    for (auto &str:numStr) {
        if(str.size()==0||str.size()>3) return "Neither";
        for(auto &c:str){
            if(!isdigit(c))
                return "Neither";
        }
        int num = stoi(str);
        if (num < 0 || num > 255 || (str[0] == '0' && str.size() != 1))
            return "Neither";
    }
    return "IPv4";
}

string isIPV6(string query) {
    vector<string> numStr = split(query,':');
    if(numStr.size()!=8)return "Neither";
    for(auto &str:numStr){
        if(str.size()==0||str.size()>4)return "Neither";
        for(auto &c:str){
            if(isdigit(c))
                continue;
            else if (isalpha(c) && ((c - 'a' >= 0 && 'f' - c >= 0) || (c - 'A' >= 0 && 'F' - c >= 0)))
                continue;
            else
                return "Neither";
        }
    }
    return "IPv6";
}

string validIPAddress(string queryIP) {
    for (auto &c:queryIP) {
        if (c == '.') {
            return isIPV4(queryIP);
        } else if (c == ':') {
            return isIPV6(queryIP);
        }
    }
    return "Neither";
}

int main() {
    string str = "2001:0db8:85a3:0:0:8A2E:0370:7334";
   cout << validIPAddress(str) << endl;
}

