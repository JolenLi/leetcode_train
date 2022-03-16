class Solution {
public:
    unordered_set<string> valid;
    unordered_set<int> illegal;
    bool check(string &s,int start){
        if(start==s.size())return true;
        if(illegal.count(start))
            return false;
        for(int posN =1;posN<=s.size()-start;posN++){
            string str = s.substr(start,posN);
            if(valid.count(str)&&check(s,start+posN))
                return true;
        }
        illegal.insert(start);
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &str:wordDict)
            valid.insert(str);
        return check(s,0);
    }
};