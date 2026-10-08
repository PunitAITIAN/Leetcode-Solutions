class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        int j = 1;
        int open = 1;
        int close = 0;
        string ans;
        while(i<s.length() && j<s.length()){
            
            if(s[j]=='('){
                open++;
            }
            if(s[j]==')'){
                close++;
            }
            // check 
            if(open==close){
                int st = i+1;
                int end = j-1;
                while(st<=end){
                    ans.push_back(s[st]);
                    st++;
                }
                open = 0;
                close=0;
                i=j+1;
            }
            j++;
        }

        return ans;
    }
};