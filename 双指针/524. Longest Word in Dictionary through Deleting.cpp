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

bool isSubStr(string &str, string &target) {
    int i = 0, j = 0;
    while (i < str.size() && j < target.size()) {
        if (str[i] == target[j]) {
            i++, j++;
        } else {
            i++;
        }
    }
    return j == target.size();
}

string findLongestWord(string s, vector<string> &dictionary) {
    string ans;
    for (string &str:dictionary) {
        int ansLen = ans.size(), strLen = str.size();
        if (ansLen > strLen || (ansLen == strLen && ans <= str))
            continue;
        if(isSubStr(s, str))
            ans = str;
    }
    return ans;
}


int main() {

}