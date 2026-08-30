class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        // edge case -> single element in array
        if(n==1) return 1;
       
        // find minimum element index
        int mini = INT_MAX;
        int miniIndex =-1;
        for(int i=0; i<n ;i++){
            if(mini>nums[i]){
                mini = nums[i];
                miniIndex = i;
            }
        }

        // find maximum element index
        int maxi = INT_MIN;
        int maxiIndex =-1;
        for(int i=0; i<n ;i++){
            if(maxi<nums[i]){
                maxi = nums[i];
                maxiIndex = i;
            }
        }

        int starting = min(miniIndex,maxiIndex);
        int ending = max(miniIndex,maxiIndex);

        int dist1 = (starting+1)+(n-ending);

        int dist2 = ending+1;

        int dist3 = n-starting;

        return min(dist1,min(dist2,dist3));
    }
};