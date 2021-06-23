//
// Created by Jolen on 2021/6/22.
//

vector<int> plusOne(vector<int>& digits) {
    int size = digits.size();
    int num = digits[size-1]+1;
    bool flag = false;
    if(num<=9)
        digits[size-1]=num;
    else{
        digits[size-1]=0;
        flag=true;
    }

    for(int i=1;i<size&&flag;i++)
    {
        int num = digits[size-i-1]+1;
        if(num<=9){
            digits[size-i-1]=num;
            flag=false;
        }
        else{
            digits[size-i-1]=0;
            flag=true;
        }
    }
    if(flag)
    {
        digits.insert(digits.begin(),1);
    }
    return digits;
}