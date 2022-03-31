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

string minWindow(string s, string t) {
    unordered_map<char, int> need;
    unordered_set<char> uniqueChar;
    int resL=0,resR=INT_MAX;
    for (auto &c:t)
        need[c]++;
    int needChar = 0;
    for (auto &it:need) {
        uniqueChar.insert(it.first);
        needChar++;
    }

    for (int l = 0, r = 0; r <= s.size();) {
        if (needChar) {
            if (uniqueChar.count(s[r])) {
                need[s[r]]--;
                if (need[s[r]] == 0)
                    needChar--;
            }
            r++;
        } else {
            if(uniqueChar.count(s[l])){
                need[s[l]]++;
                if(need[s[l]]==1) {
                    if(r-l<resR-resL)
                        resR=r,resL=l;
                    needChar++;
                }
            }
            l++;
        }
    }
    return resR==INT_MAX?"":s.substr(resL,resR-resL);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;
}