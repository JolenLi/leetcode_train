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

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> charMap;
    unordered_map<char, int> check;
    int len = s1.size() ;
    int r = 0;
    for (auto &c:s1)
        charMap[c]++;
    check = charMap;
    for (int i = 0; i < s2.size(); i++) {
        if (i != 0 && check[s2[i - 1]])
            charMap[s2[i - 1]]++;

        if (r == i && !charMap[s2[r]]){
            r++;
            continue;
        }

        while (charMap[s2[r]]) {
            charMap[s2[r]]--;
            r++;
        }
        if (r - i == len)
            return true;

    }
    return false;
}

int main() {
    string s1 = "ab", s2 = "ba";
    cout << checkInclusion(s1, s2) << endl;
}