string& strreverse(string &s)
{
    for (size_t i = 0; i < s.size() >> 1; ++i)
    {
        char temp = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = s[i];
        s[i] = temp;
    }
    return s;
}

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0)
        {
            n--;
            result.push_back('A' + n % 26);
            n /= 26;
        }
        return strreverse(result);
    }
};