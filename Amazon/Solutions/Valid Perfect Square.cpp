class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = sqrt(num);

        if(s*s == num ) return true;
        return false;
    }
};