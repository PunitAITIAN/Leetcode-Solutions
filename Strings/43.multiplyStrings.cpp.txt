class Solution {
public:
    void rev(string& s){
        int size = s.length();
        int st =0; 
        int e = size-1;

        while(st<e){
            swap(s[st],s[e]);
            st++;
            e--;
        }
    }
    string multiply(string num1, string num2) {

        string ans;

        int m = num1.length();

        int n = num2.length();

        // reverse strings
        rev(num1);
        rev(num2);
        
        // create a vector of m+n size
        vector<int> store(m+n+1);

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                store[i+j]+= (num1[i]-'0')*(num2[j]-'0');
            }
        }

        // add numbers in vector
        for(int i=0; i<m+n ;i++){
            int power = store[i]/10;
            store[i]=(store[i]%10) ;
            store[i+1]+=power;
        }

        // reverse vector
        int s =0;
        int e = m+n;

        while(s<=e){
            swap(store[s],store[e]);
            s++;
            e--;
        }

        // remove leading zeroes
        int first = 0;
        while(first<=m+n && store[first]==0){
            first++;
        }
        // store number into string

        if(first>m+n) return "0";

        for(int i=first;i<m+n+1;i++){
            ans.push_back(store[i]+'0');
        }
        return ans;
    }
};