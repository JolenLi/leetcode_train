//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;
string reverseStr(string s, int k) {
    int n = s.size();
    string str="";
    int maxIndex = min(k,n);
    for(int i=maxIndex-1;i>=0;i--){
        str+=s[i];
    }
    for(int i=maxIndex;i<s.size()&&i<2*k;i++)
        str+=s[i];
    if(s.size()>2*k)
        str +=reverseStr(s.substr(2*k),k);
    return str;
}
int main()
{
    string s= "abcdefghijk";
    isnumb
    cout<<reverseStr(s,2)<<endl;

}//
// Created by Jolen on 2021/6/24.
//

