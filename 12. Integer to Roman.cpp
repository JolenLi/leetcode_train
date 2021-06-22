//
// Created by Jolen on 2021/6/22.
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


vector<vector<int>> intNum = {{1,   5,   10},
                              {10,  50,  100},
                              {100, 500, 1000}};
vector<vector<string>> charNum = {{"I", "V", "X"},
                                {"X", "L", "C",},
                                {"C", "D", "M"},{"M"}};

string intToRoman(int num) {
    string str = "";
    int index = 0;
    while (num) {
        index++;
        int last = num % 10;
        num -= last;
        num /=10;
        if (last == 1)
            str = charNum[index - 1][0] + str;
        else if (last == 2)
            str = charNum[index - 1][0]+charNum[index - 1][0]+str;
        else if (last == 3)
            str = charNum[index - 1][0]+charNum[index - 1][0]+charNum[index - 1][0]+str;
        else if (last == 4)
            str = charNum[index - 1][0]+charNum[index - 1][1]+str;
        else if (last == 5)
            str = charNum[index - 1][1]+str;
        else if (last == 6)
            str = charNum[index - 1][1]+charNum[index - 1][0]+str;
        else if (last == 7)
            str = charNum[index - 1][1]+charNum[index - 1][0]+charNum[index - 1][0]+str;
        else if (last == 8)
            str = charNum[index - 1][1]+charNum[index - 1][0]+charNum[index - 1][0]+charNum[index - 1][0]+str;
        else if (last == 9)
            str = charNum[index - 1][0]+charNum[index - 1][2]+str;
        cout<<str<<endl;
    }

}

int main() {
    int num = 1234;
    cout << intToRoman(num);
}
