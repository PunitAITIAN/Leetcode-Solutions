class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(int i=0; i<26;i++){
            if(i<8){
                arr[i]=1;
            }
            else if(i<16){
                arr[i]=2;
            }
            else if(i<24){
                arr[i]=3;
            }
            else{
                arr[i]=4;
            }
        }

        int n = word.length();
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }

        return ans;
    }
};