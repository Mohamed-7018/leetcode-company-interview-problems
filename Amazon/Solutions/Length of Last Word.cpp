class Solution {
public:
    int lengthOfLastWord(string s) {
        int ANS=0;
        for(int i = s.size()-1;i>=0;i--) {
            if (s[i] == ' ' && ANS)break;
            else if(s[i] != ' ') ANS++;
        }

        return ANS;
    }
};