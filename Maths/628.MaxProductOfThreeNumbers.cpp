#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int maxProduct = INT_MIN;

        int size = nums.size();

        // if there are all positive numbers , all last three biggest numbers
        int max1 = nums[size-1];
        int max2 = nums[size-2];
        int max3 = nums[size-3];

        maxProduct = max1*max2*max3;

        // if there are negative numbers also , check that also first two negative numbers and last biggest number
        max1 = nums[size-1];
        max2 = nums[0];
        max3 = nums[1];

        maxProduct = max(maxProduct , (max1*max2*max3));

        return maxProduct;

    }
};
