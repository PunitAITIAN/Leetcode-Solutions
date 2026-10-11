class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        // let get smallest string
        int miniIndx = 0;
        for(int i=0; i<strs.size();i++){
            if(strs[i].length()<strs[miniIndx].length()){
                miniIndx = i;
            }
        }
        string smallest = strs[miniIndx];

        for(int i=0; i<smallest.length();i++){
            char ch = smallest[i];
            for(auto str : strs){
                if(ch!=str[i]){
                    return ans;
                }
            }
            ans.push_back(ch);
        }

        return ans;
    }
};