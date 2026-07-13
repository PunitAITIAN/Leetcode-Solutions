class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        vector<int> count(26,0);

        for(int i=0 ; i<t.length() ; i++){
            count[t[i]-'a']++;
        }

        for(auto v : count){
            cout<<v<<" ";
        }
        cout<<endl;

        for(int i=0;i<s.length();i++){
            count[s[i]-'a']--;
        }

        for(auto v : count){
            cout<<v<<" ";
        }
        cout<<endl;

        for(int i=0; i<26 ;i++){
            if(count[i]!=0){
                cout<<i<<endl;
                ans = i+'a';
                break;
            }
        }
        return ans;
    }
};