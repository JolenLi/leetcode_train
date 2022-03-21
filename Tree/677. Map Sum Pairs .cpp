//
// Created by Jolen on 2022/3/19.
//


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include <unordered_set>

using namespace std;


//// 字典树

class Trie {
private:
    vector<Trie *> child;
    int val;
public:
    Trie() : child(vector<Trie *>(26, nullptr)), val(0) {};
    void insert(string str,int val){
        Trie* cur = this;
        for (char &ch:str) {
            int idx = ch-'a';
            if(!cur->child[idx])
                cur->child[idx] = new Trie();
            cur = cur->child[idx];
            cur->val += val;
        }
    }

    int getSum(string prefix){
        int sum = 0;
        Trie *cur = this;
        for(char &ch:prefix){
            cur = cur->child[ch-'a'];
            if(!cur)return 0;
            sum+=cur->val;
        }
        return sum;
    }
};

class MapSum {
private:
    Trie *trie;
    unordered_map<string,int> valMap;
public:
    MapSum() {
        this->trie = new Trie();
    }

    void insert(string key, int val) {
        int number = val-valMap[key];
        valMap[key] = val;
        this->trie->insert(key,number);
    }

    int sum(string prefix) {
        return this->trie->getSum(prefix);
    }
};

int main() {
    WordDictionary *test = new WordDictionary();
    vector<string> strs = {"dad", "dad", "mad", "pad", "bad"};
    for (string str:strs)
        test->addWord(str);
    cout << test->search(".ad") << endl;
}