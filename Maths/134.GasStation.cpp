class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit =0;
        int balance =0;
        int start =0;
        for(int i=0; i<gas.size();i++){
            // ya toh main aage ja sakta hu ya nahi ja sakta
            if(balance + gas[i] < cost[i]){
                // deficit case , aage nahi ja sakta
                deficit += balance+gas[i]-cost[i];
                start=i+1;
                balance=0;
            }
            else{
                // aage ja sakta hu , extra petrol bhi ho sakta h
                balance += gas[i]-cost[i];
            }
        }
        // ab loop khatam , we can compare deficit and balance
        if(balance+deficit>=0){
            // iska matlab balance ne deficit ko fill kardia ya exceed kardia
            return start;
        }
        else{
            // petrol kam pad gaya , no answer
            return -1;
        }
    }
};