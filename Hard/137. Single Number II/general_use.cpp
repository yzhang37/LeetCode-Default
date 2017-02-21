class Solution {
public:
    int singleNumber(vector<int>& nums, int k) {
        int m = (int)ceil(log2((double)k));
        vector<int>x(m, 0);
        for (size_t index = 0; index < nums.size(); ++index)
        {
            for (int i = m - 1; i >= 0; --i)
            {
                int num = nums[index];
                for (int j = 0; j < i; ++j)
                    num &= x[j];
                x[i] ^= num;
            }
            int mask, ck = k;
            mask = ((ck & 1) ? x[0] : ~x[0]);
            for (int i = 1; i < m; ++i)
            {
                ck >>= 1;
                mask &= ((ck & 1) ? x[i] : ~x[i]);
            }
            mask = ~mask;
            for (int i = 0; i < m; ++i)
                x[i] &= mask;
        }
        int result = 0;
        for (int j = 0; j < 32; ++j)
        {
            int count = 0;
            for (int i = 0; i < m; ++i)
            {
                count = (count + (x[i] & 1)) % k;
                x[i] >>= 1;
            }
            if (count)
                result |= 1 << j;
        }
        return result;
    }
};