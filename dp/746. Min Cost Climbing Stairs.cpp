int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int a =0,b=0;
    int costI = 0;
    for(int i=0;i<cost.size();i++){
        costI = min(a,b)+cost[i];
        a=b;
        b=costI;
    }
    return costI;
}