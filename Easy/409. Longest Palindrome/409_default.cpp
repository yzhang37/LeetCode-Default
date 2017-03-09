class Solution {
public:
    int longestPalindrome(string s) {
        map <char, int> vmap;
        bool odd = false;
        int res = 0;
        size_t len = s.size();
        for (size_t i = 0; i < len; ++i)
        {
            if (!vmap.count(s[i]))
                vmap[s[i]] = 1;
            else
                vmap[s[i]]++;
        }
        for (auto i = vmap.begin();
            i != vmap.end();
            i++)
        {
            if (i->second & 1)
                odd = true;
            res += (i->second & ~1);
        }
        if (odd)
            res++;
        return res;
    }
};