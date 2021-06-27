//
// Created by Jolen on 2021/6/26.
//
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

#include <bitset>

using namespace std;

int maxProduct(vector<string> &words) {
    vector<int> exist(words.size() , 0);
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
        for (auto &c:words[i]) {
            exist[i] |= (1 << (c - 'a'));
        }
    }


    for (int i = 0; i < words.size(); i++)
        for (int j = i + 1; j < words.size(); j++) {
            if ((exist[i] & exist[j]) == 0) {
                int size = words[i].size() * words[j].size();
                ans = max(ans, size);
            }
        }
    return ans;
}

int main() {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(words) << endl;
}
