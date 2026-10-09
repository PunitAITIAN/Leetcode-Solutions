class Solution {
public:
    int minInsertions(string s) {
        int result = 0; // storing insertions

        int count = 0; // counting opening brackets

        int i=0;
        int n = s.length();
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }
            else{
                // check if open bracket is present before open bracket or not
                if(count > 0){
                    count--;
                }
                else{
                    result+=1;  // adding one missing open bracket
                }

                // ) close bracket
                if(i+1<n && s[i+1]==')'){
                    // consecutive close brackets
                    i+=2;
                }
                else{
                    i+=1;
                    result+=1; // add one missing closing bracket
                }
            }
        }

        // count*2 because if there is any open bracket present without 2 close brackets
        // eg . ())(
        return result+(count*2);
    }
};