class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=0;
        int e =num;
        while(s<=e){
            int mid = s + (e-s)/2;
            long long mult = 1LL*mid*mid;
            if(mult==num){
                return true;
            }
            else if(mult>num){
                //move to left
                e=mid-1;
            }
            else{
                // move to right
                s = mid+1;
            }
        }
        return false;
    }
};