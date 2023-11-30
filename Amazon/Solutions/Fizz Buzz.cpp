#define ll  long long
#define pb push_back

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(i%3 == 0 && i%5 == 0) ans.pb("FizzBuzz");
            else if(i%3 == 0) ans.pb("Fizz");
            else if(i%5 == 0) ans.pb("Buzz");
            else ans.pb(to_string(i));
        }
        return ans;
    }
};