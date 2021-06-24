//
// Created by Jolen on 2021/6/24.
//


int firstUniqChar(string s) {
    int* freq = new int[100];
    for(int i =0;i<100;i++)
        freq[i]=0;
    for(int i =0;i<s.size();i++)
        freq[s[i]-'a']+=1;

    for(int i =0;i<s.size();i++)
        if(freq[s[i]-'a']==1)
            return i;
    return -1;


//     unordered_map<char,int> charFreq;
//     char ans='-1';
//     for(int i =0;i<s.size();i++)
//         charFreq[s[i]]+=1;
//     for(int i =0;i<s.size();i++)
//         if(charFreq[s[i]]==1){
// ans = s[i];break;
//         }

//     return s.find(ans);
}
