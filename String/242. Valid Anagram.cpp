//
// Created by Jolen on 2021/6/24.
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int *freq = new int[26];
        for(int i =0;i<26;i++)
            freq[i]=0;
        for(auto c:s)
            freq[c-'a']++;
        for(auto c:t){
            freq[c-'a']--;
            if(freq[c-'a']<0)
                return false;
        }
        return true;
    }
};