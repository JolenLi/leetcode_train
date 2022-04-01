//
// Created by Jolen on 2022/3/31.
//

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

bool isValid(string &s, int lo, int hi, int times) {
    if (lo > hi) return true;
    if (s[lo] != s[hi]) {
        if (times == 0)
            return false;
        else
            return isValid(s, lo + 1, hi, times - 1) ||
                   isValid(s, lo, hi - 1, times - 1);
    } else
        return isValid(s, lo + 1, hi - 1, times);
}

bool validPalindrome(string s) {
    return isValid(s, 0, s.size() - 1, 1);
}



int main() {

}