class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        // edge case
        if(arr.empty()) return {};

        vector<int> temp(arr.size());
        // copy arr values in temp array
        for(int i=0; i<arr.size();i++){
            temp[i]=arr[i];
        }

        // sort array
        sort(temp.begin(),temp.end());

        // make ans array
        vector<int> ans(arr.size());

        // make a hashmap for storing rank of a number
        unordered_map<int,int> rank ;

        //put ranks of each number in map
        int ranki =1;

        rank[temp[0]]=ranki;

        for(int i=1; i<temp.size() ; i++){
            if(temp[i]>temp[i-1]){
                ranki++;
            }
            rank[temp[i]]=ranki;
        }

        // put rank in ans array
        for(int i=0; i<ans.size();i++){
            ans[i]=rank[arr[i]];
        }

        return ans;
    }
};