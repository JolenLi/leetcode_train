//
// Created by Jolen on 2021/6/24.
//

void reverseString(vector<char>& s) {
    int n = s.size()-1;
    for(int i=0;i<n;i++,n--)
        swap(s[i],s[n]);
}