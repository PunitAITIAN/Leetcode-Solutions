class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int num = 1;
        int i=0;
        while(i<arr.size()){
            // check if kth missing element is achieved or not
            if(missing.size()==k) break;

            if(arr[i]==num){
                i++;
            }
            else{
                missing.push_back(num);
            }
            num++;
        }

        if(missing.size()==k){
            return missing[missing.size()-1];
        }
        else{
            return arr[arr.size()-1]+(k-missing.size());
        }
    }
};