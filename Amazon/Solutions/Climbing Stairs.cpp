class Solution {
private:
    int ANS;
public:
    Solution(){
        ANS = 0;
    }
    int ncr(int n , int r) {
        double sum = 1;
        for(int i=1 ;i<=r;i++) {
            sum = sum * (n-r+i)/i;
        }
        return (int) sum ;
    }
    int climbStairs(int n) {
        // 1 1 1 1
        // 1 2 1 
        // 1 1 2
        // 2 1 1
        // 2 2

        int ANS = 0;

      int numberOfMaxTwos = n / 2 ;
      cout << numberOfMaxTwos <<endl;


      for(int i=0;i<=numberOfMaxTwos;i++) {
        int  R = n - 2 * i;
         int N = R + i ;

         ANS += ncr(N,R);
         cout << i << '-' << ANS <<endl;
      }
      return ANS ;
    }
};