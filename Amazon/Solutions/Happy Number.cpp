class Solution {
private:
    int nextNumber(int n) {
        int ret = 0;
        while(n) {
            int num= n%10;
            ret += num*num;
            n = n/10;
        }

        return ret;
    }
public:
    bool isHappy(int n) {
      set<int> s;
      while(n!=1) {
          int lengthBefore = s.size();
          s.insert(n);
          int lengthAfter = s.size();
          if(lengthBefore == lengthAfter) break;
          cout << n << ' ' ;
          n= nextNumber(n);
      }

      return n==1;
    }
};