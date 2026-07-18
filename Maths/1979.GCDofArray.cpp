#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = INT_MIN;
        int smallest = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>largest){
                largest = nums[i];
            }
            if(nums[i]<smallest){
                smallest = nums[i];
            }
        }
        return __gcd(smallest , largest);
    }
};