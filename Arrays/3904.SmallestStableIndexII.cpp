class Solution {
public:
    void findMax(vector<int>& maxElement,vector<int>& nums){
        int maxi =INT_MIN;
        for(int i=0 ;i<nums.size() ;i++){
          if(maxi<nums[i]) {
              maxi=nums[i];
          } 
            maxElement[i]=maxi;
        }
    }
    void findMin(vector<int>& minElement,vector<int>& nums){
        int mini =INT_MAX;
        for(int i=nums.size()-1;i>=0 ;i--){
          if(mini>nums[i]) {
              mini=nums[i];
          } 
            minElement[i]=mini;
        }
    }
    
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
       vector<int> maxElement(n);
       vector<int> minElement(n);
       vector <int> ans(n);

        findMax(maxElement,nums);
        findMin(minElement,nums);

        for(int i=0;i<nums.size();i++){
            ans[i]=maxElement[i]-minElement[i];
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]<=k){
                return i;
            }
        }
        return -1;
    }
};