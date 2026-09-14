class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //touching , outside -> return false
        // 4 cases
        // rec 1 is in left side and rec 2 is in right side
        // rec 2 is in left side and rec 1 is in right side
        // rec 1 is at bottom and rec 2 is at top
        // rec 2 is at bottom and rec 1 is at top
        if((rec1[2]<=rec2[0])||(rec2[2]<=rec1[0])||(rec1[3]<=rec2[1])||(rec2[3]<=rec1[1])){
            return false;
        }
        // intersection case -> return true
        return true;
    }
};