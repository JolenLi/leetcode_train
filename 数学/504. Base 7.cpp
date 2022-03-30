//
// Created by Jolen on 2022/3/29.
//

int BASE = 7;
string convert(int num){
    if(num<7)
        return to_string(num);
    return convert(num/BASE)+to_string(num%BASE);
}
string convertToBase7(int num) {
    bool flag = num>=0?true:false;
    string res = convert(abs(num));
    if(flag==false)
        res = "-"+res;
    return res;
}