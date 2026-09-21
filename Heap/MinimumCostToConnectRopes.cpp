class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue <int,vector<int> ,greater<int>> pq;
        
        // insert array elements into priority queue
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        int totalCost = 0;
        
        while(pq.size()>1){
            int element1 = pq.top();
            pq.pop();
            
            int element2 = pq.top();
            pq.pop();
            
            int sum = element1 + element2;
            
            pq.push(sum);
            totalCost+=sum;
        }
        
        return totalCost;
    }
};