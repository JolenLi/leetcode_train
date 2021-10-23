//
// Created by Jolen on 2021/10/23.
//


class NestedIterator {
private:
    vector<int> listInt;
    int pos=0;
    void dfs(vector<NestedInteger> &nestedList){
        for(auto nest: nestedList)
            if(nest.isInteger())
                listInt.push_back(nest.getInteger());
            else
                dfs(nest.getList());
    }
public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    int next() {
        return listInt[pos++];
    }

    bool hasNext() {
        return pos<listInt.size();
    }
};