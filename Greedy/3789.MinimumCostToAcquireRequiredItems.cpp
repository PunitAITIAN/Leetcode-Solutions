class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // base case
        if(need1 == 0 && need2 ==0 ) return 0;

        long long commonNeed = min(need1 , need2)*1LL;

        long long maxi = max(need1,need2)*1LL;

        long long priceAllBoth = maxi*1LL* costBoth;

        long long priceIndividual = (need1*1LL*cost1)+(need2*1LL*cost2);

        need1 -= commonNeed;
        need2 -= commonNeed;

        long long priceCommon = (commonNeed * 1LL * costBoth )+(need1*1LL*cost1)+(need2*1LL*cost2);

        return min(priceIndividual,min(priceAllBoth,priceCommon));
    }
};