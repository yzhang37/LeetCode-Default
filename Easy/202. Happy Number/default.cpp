class Solution {
public:
    bool isHappy(int n) {
        set <int> s;
        while (n != 1 && !s.count(n))
        {
            s.insert(n);
            int m = 0;
            while (n > 0)
            {
                m += (n % 10) * (n % 10);
                n /= 10;
            }
            n = m;
        }
        return n == 1;
    }
};