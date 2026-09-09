class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        // adding 1st comma
        if(n>=1000 ){
            ans+=(n-999);
        }
        // adding 2nd comma
        if(n>=1000000 ){
            ans+=(n-999999);
        }
        // adding 3rd comma
        if(n>=1000000000 ){
            ans+=(n-999999999);
        }
        // adding 4th comma
        if(n>=1000000000000 ){
            ans+=(n-999999999999);
        }
        // adding 5th comma
        if(n==1000000000000000){
            ans++;
        } 

        return ans;
    }
};