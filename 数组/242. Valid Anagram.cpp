

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
bool isAnagram(string s, string t) {
    vector<int> vec(26,0);
    if(s.size()!=t.size())return false;
    for(auto &c:s)
        vec[c-'a']++;

    for(auto &c:t){
        vec[c-'a']--;
        if(vec[c-'a']<0)
            return false;
    }
    return true;
}
int main() {
  cout<<isAnagram("cbb","abc");
}