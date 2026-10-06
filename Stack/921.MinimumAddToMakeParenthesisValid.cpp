class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int open = 0;
        int close = 0;
        // main logic
        stack<int> st;
        // so basically i want no of unpaired brackets
        // let us count no of unpaired open and close brackets
        for(int i=0; i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    close++;
                }
            }
        }

        while(!st.empty()){
            open++;
            st.pop();
        }

        ans = open+close;

        return ans;
    }
};