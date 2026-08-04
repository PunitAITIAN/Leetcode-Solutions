class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        // find smallest element
        int smallest = INT_MAX;
        for(int i=0; i<n ;i++){
            if(smallest>nums[i]){
                smallest = nums[i];
            }
        }

        // largest element
        int largest = INT_MIN;
        for(int i=0; i<n ;i++){
            if(largest<nums[i]){
                largest = nums[i];
            }
        }
        // vector which will store missing values
        vector<int>ans;

        // map for storing present values
        unordered_map<int,bool> mapCount;

        // marking nums values as true
        for(int i=0;i<nums.size();i++){
            mapCount.insert({nums[i],true});
        }
        
        // push missing values
        for(int i=smallest ;i<=largest ;i++){
            if(mapCount.find(i)==mapCount.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};