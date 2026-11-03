class Solution {
public:
    int minMoves(vector<int>& nums) {
        // find maxmum element
        // also find sum of all elements of nums array
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        int n = nums.size();
        return (n*maxi)-sum ;
    }
};