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


using namespace std;


class trie {
private:
    vector<trie *> next;
    bool isEnd;
public:
    trie() {
        next = vector<trie *>(26, nullptr);
        isEnd = false;
    }

    void insertNode(string &word) {
        trie *cur = this;
        for (auto &c:word) {
            int idx = c - 'a';
            if (!cur->next[idx])
                cur->next[idx] = new trie();
            cur = cur->next[idx];
        }
        cur->isEnd = true;
    }

    bool search(string cur) {
        trie *root = this;
        for (char &c:cur) {
            int idx = c - 'a';
            root = root->next[idx];
            if (!root || !root->isEnd)
                return false;
        }
        return true;
    }
};





string longestWord(vector<string> &words) {
    string res = "";
    trie *root = new trie();
    for (string word:words)
        root->insertNode(word);

    for (string &word:words)
        if (root->search(word))
            if (word.size() > res.size() || (word.size() == res.size() && word < res))
                res = word;

    return res;
}

int main() {
    vector<string> words = {"yo", "ew", "fc", "zrc", "yodn", "fcm", "qm", "qmo", "fcmz", "z", "ewq", "yod", "ewqz",
                            "y"};
    cout << longestWord(words) << endl;
}