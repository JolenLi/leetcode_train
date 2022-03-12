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

string reverseWords(string s) {
    string newStr = "";
    int cnt = 0;
    while (cnt < s.size() && s[cnt] == ' ')
        cnt++;
    s = s.substr(cnt);
    reverse(s.begin(), s.end());

    int start = 0, end = 0;
    while (start < s.size()) {
        while (start < s.size() && s[start] == ' ')
            start++;
        end = start;
        while (end < s.size() && s[end] != ' ')
            end++;
        reverse(s.begin() + start, s.begin() + end);
        newStr += s.substr(start, end - start) + " ";
        start = end + 1;
    }
    newStr = newStr.substr(0, newStr.size() - 1);
    return newStr;
}

int main() {
    cout << reverseWords(" aaaa  bbbb ccc  ");
}