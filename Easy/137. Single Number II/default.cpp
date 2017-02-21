class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>x(2,0);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int &num = nums[i];
            x[1] ^= (x[0] & num);
            x[0] ^= num;
            int mask = ~(x[1] & x[0]);
            x[1] &= mask;
            x[0] &= mask;
        }
        return x[0];
    }
};
