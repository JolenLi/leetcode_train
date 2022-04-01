//
// Created by Jolen on 2022/3/31.
//

//
// Created by Jolen on 2022/3/31.
//



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

unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

string reverseVowels(string s) {
    int lo = 0, hi = s.size() - 1;
    string ans = s;
    while (lo <= hi) {
        if (!vow.count(s[lo])) {
            lo++;
        } else if (!vow.count(s[hi])) {
            hi--;
        } else {
            ans[lo] = s[hi];
            ans[hi--] = s[lo++];
        }
    }
    return ans;
}

int main() {

}