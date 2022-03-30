//
// Created by Jolen on 2022/3/29.
//

void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    move(A.size(),A,B,C);
}
void move(int n,vector<int>& A, vector<int>& B, vector<int>& C){
    if(n==1){
        int num = A[A.size()-1];
        A.pop_back();
        C.push_back(num);
        return;
    }
    move(n-1,A,C,B);
    move(1,A,B,C);
    move(n-1,B,A,C);
}