class Solution {
public:
    int titleToNumber(string s) {
        int num = 0, len = s.size();
        for (int i = 0; i < len; ++i)
        {
            int d = s[i] - 'A';
            num = num * 26 + d + 1;
        }
        return num;
    }
};