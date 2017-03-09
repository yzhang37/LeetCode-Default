class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = n & 1;
        while (n >>= 1)
            cnt += (n & 1);
        return cnt;
    }
};