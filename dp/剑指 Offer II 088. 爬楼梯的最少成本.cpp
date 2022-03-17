int minCostClimbingStairs(vector<int>& cost) {
    int a=0,b=0;
    int next=0;
    for(int i=0;i<cost.size();i++){
        next = min(a,b)+cost[i];
        a=b;
        b=next;
    }
    return min(a,b);
}