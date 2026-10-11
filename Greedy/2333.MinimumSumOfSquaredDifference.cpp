class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        int n = nums1.size();
        // vector for storing diff frequency
        vector<int> diff(1e5+1,0);

        for(int i =0; i<n ;i++){
            int d = abs(nums1[i]-nums2[i]);
            diff[d]++;
        }

        int total = k1+k2;

        int end = diff.size()-1;

        while(end>0 && total>0){
            int countOps = min(diff[end],total);
            diff[end]-=countOps;
            diff[end-1]+=countOps;
            total-=countOps;
            end--;
        }

        for(long long i=0; i<diff.size();i++){
            ans+=(diff[i]*i*i*1LL);
        }
        
        return ans;
    }
};