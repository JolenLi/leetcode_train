//
// Created by Jolen on 2022/3/29.
//

class Solution {
public:
    int get(string &a,int i){
        int idx = a.size()-i-1;
        if(idx>=a.size()||idx<0)
            return 0;
        return a[idx]-'0';
    }
    string addBinary(string a, string b) {
        int n = max(a.size(),b.size());
        string ans;
        int add=0;
        for(int i =0;i<n;i++){
            add += get(a,i)+get(b,i);
            ans += (add%2+'0');
            add /= 2;

        }
        if(add)
            ans+= add+'0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};