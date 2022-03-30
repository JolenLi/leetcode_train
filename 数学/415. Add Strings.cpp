//
// Created by Jolen on 2022/3/29.
//

string addStrings(string num1, string num2) {
    string ans;
    int carry=0;
    for(int i=num1.size()-1,j=num2.size()-1;i>=0||j>=0;i--,j--){
        if(i>=0)
            carry+=num1[i]-'0';
        if(j>=0)
            carry+=num2[j]-'0';
        ans+= carry%10+'0';
        carry /= 10;
    }
    if(carry)
        ans += carry+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}