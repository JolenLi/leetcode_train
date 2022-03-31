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

int lengthOfLongestSubstring(string s) {

    unordered_set<char> set;
    int r = 0;
    int res = 0;
    for(int l = 0;l<s.size();l++){
        while(r<s.size()&&!set.count(s[r])){
            set.insert(s[r++]);
        }
        set.erase(s[l]);
        res = max(res,r-l);

    }
    return res;
}

int main() {
    string str = "aa";
    cout << lengthOfLongestSubstring(str) << endl;
}