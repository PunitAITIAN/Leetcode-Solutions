class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // store knowledge key values pairs in map
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }

        string ans;
        // now ans
        int i=0;
        int n = s.size();
        while(i<n){
            if(s[i]=='('){
                int st = i;
                while(s[i]!=')'){
                    i++;
                }
                string str = s.substr(st+1,i-st-1);
                if(mp.find(str)!=mp.end()){
                    ans+=mp[str];
                }
                else{
                    ans+="?";
                }
            }
            if(s[i]!=')' && s[i]!='('){
                ans.push_back(s[i]);
                i++;
            }
            if(s[i]==')') i++;
        }
        return ans;
    }
};