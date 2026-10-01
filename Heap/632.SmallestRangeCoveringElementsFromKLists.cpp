class Solution {
public:
    class info{
        public:
        int data;
        int rIndex;
        int cIndex;

        info(int val , int i , int j){
            this->data = val;
            this->rIndex = i;
            this->cIndex = j;
        }
    };
    class compare{
        public:
        bool operator()(info A , info B){
            return A.data > B.data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // storing ans
        vector<int> ans;


        // temp mini and maxi
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int totalRows = nums.size();
        // create min heap
        priority_queue<info, vector<info> , compare> pq;

        for(int i=0 ; i<totalRows ; i++){
            info element(nums[i][0],i,0);
            pq.push(element);
            maxi = max(maxi , element.data);
            mini = min(mini, element.data);
        }

        int ans_mini = mini;
        int ans_maxi = maxi;
        
        // main logic
        while(!pq.empty()){
            info front = pq.top();
            pq.pop();

            mini = front.data;

            if(maxi-mini < ans_maxi-ans_mini){
                ans_maxi = maxi;
                ans_mini = mini;
            }

            if((front.cIndex+1) < (nums[front.rIndex].size())){
                info element(nums[front.rIndex][front.cIndex+1],front.rIndex,front.cIndex+1);
                pq.push(element);
                maxi = max(maxi , element.data);
            }
            else{
                break;
            }
        }

        ans.push_back(ans_mini);
        ans.push_back(ans_maxi);

        return ans;
    }
};