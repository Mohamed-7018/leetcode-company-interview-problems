class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> mp;
        for(char it : s) {
            mp[it]++;
            if (mp[it] % 2)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};