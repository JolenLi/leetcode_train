//
// Created by Jolen on 2021/6/24.
//

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int start = 0;
        bool posFlag = true;
        for(;start<s.size()-1;start++)
        {
            if(s[start]!=' ')
                break;
        }
        if(s[start]=='-'){
            posFlag=false;
            start++;
        }else if(s[start]=='+'){
            posFlag=true;
            start++;
        }
        for(;start<s.size();start++)
        {
            if(s[start]>='0'&&s[start]<='9')
            {
                if(num>INT_MAX/10 || num==INT_MAX/10 && (s[start]-'0' > 7))
                    return posFlag?INT_MAX:INT_MIN;
                num*=10;
                num+=s[start]-'0';
            }else{
                break;
            }
        }
        if(!posFlag)
            num = -num;
        return num;

    }
};