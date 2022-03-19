//
// Created by Jolen on 2022/3/19.
//



class TripleInOne {
public:

    vector<int> stack;
    int size;
    int N=3;
    vector<int> pos;
    TripleInOne(int stackSize) {
        this->size = stackSize;
        stack = vector<int>(stackSize*N,0);
        pos = vector<int>(N,0);
    }

    void push(int stackNum, int value) {
        if(pos[stackNum]<size){
            stack[pos[stackNum]*N+stackNum] = value;
            pos[stackNum]++;
        }
    }

    int pop(int stackNum) {
        if(pos[stackNum]>0){
            int res = stack[(pos[stackNum]-1)*N+stackNum];
            pos[stackNum]--;
            return res;
        }else
            return -1;
    }

    int peek(int stackNum) {
        if(pos[stackNum]>0){
            int res = stack[(pos[stackNum]-1)*N+stackNum];
            return res;
        }else
            return -1;
    }

    bool isEmpty(int stackNum) {
        return pos[stackNum]==0?true:false;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */