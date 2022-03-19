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

//// dfs
//class WordDictionary {
//private:
//    unordered_set<string> match;
//public:
//    WordDictionary() {
//    }
//    void addWord(string word) {
//        this->match.insert(word);
//    }
//    bool check(string &word,string last,int idx){
//        if(word.size()==idx)
//            return match.count(last);
//        string cur;
//        if(word[idx]!='.'){
//            cur = last + word[idx];
//            return check(word,cur,idx+1);
//        }else{
//            for(int i =0;i<26;i++){
//                char c = 'a'+i;
//                cur = last + c;
//                if(check(word,cur,idx+1))
//                    return true;
//            }
//            return false;
//        }
//    }
//    bool search(string word) {
//        return check(word,"",0);
//    }
//};


//// 字典树

class Trie {
private:
    vector<Trie *> next;
    bool isEnd;
public:
    Trie() : next(vector<Trie *>(26, nullptr)), isEnd(false) {};

    void insert(string &word) {
        Trie *root = this;
        for (char &c:word) {
            int idx = c - 'a';
            if (root->next[idx] == nullptr)
                root->next[idx] = new Trie();
            root = root->next[idx];
        }
        root->isEnd = true;
    }

    bool match(string &word, int idx) {
        Trie *root = this;
        if (idx == word.size())
            return root->isEnd;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                Trie *child = root->next[i];
                if (child && child->match(word, idx + 1))
                    return true;
            }
            return false;
        } else {
            int i = word[idx] - 'a';
            Trie *child = root->next[i];
            return child != nullptr && child->match(word, idx + 1);
        }
    }
};

class WordDictionary {
private:
    Trie *root;
public:
    WordDictionary() {
        this->root = new Trie();
    }

    void addWord(string word) {
        this->root->insert(word);
    }

    bool search(string word) {
        return this->root->match(word, 0);
    }
};


int main() {
    WordDictionary *test = new WordDictionary();
    vector<string> strs = {"dad","dad","mad","pad","bad"};
    for(string str:strs)
        test->addWord(str);
    cout << test->search(".ad") << endl;
}