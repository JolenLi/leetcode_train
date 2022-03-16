//
// Created by Jolen on 2021/6/21.
//
#include<vector>
#include<iostream>
#include<queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;


vector<string> result;


bool isValid(string s) {
    if (stoi(s) > 255)return false;
    if (s[0] == '0' && s.size() != 1)return false;
    return true;
}

void splitNext(string now, string remain, int times) {
    if (times == 0) {
        if (isValid(remain))
            result.push_back(now + remain);
        return;
    } else if (remain.size() > (times + 1) * 3)
        return;
    int r = min((int) remain.size() - times, 3);
    for (int len = r; len > 0; len--) {
        string splitNow = remain.substr(0, len);
        if (!isValid(splitNow))continue;
        string nextNow = now + splitNow + ".";
        string nextStr = remain.substr(len, remain.size() - len);
        splitNext(nextNow, nextStr, times - 1);
    }
}

vector<string> restoreIpAddresses(string s) {
    string now = "";
    splitNext(now, s, 3);
    return result;
}

int main() {
    string str = "101023";
    for (auto i:restoreIpAddresses(str))
        cout << i << endl;
}