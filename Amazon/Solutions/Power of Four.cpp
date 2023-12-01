#define ll long long
class Solution {
public:
    bool isPowerOfFour(int n) {
    ll  num = n / 4;
    ll p = 0;
    while (num != 0) {
      num = num/ 4;
      p++;
    }
    return pow(4, p) == n;
    }
};