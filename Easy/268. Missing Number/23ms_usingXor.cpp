class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        int has0 = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] == 0) has0 = 1;
            num ^= nums[i];
        }
        for (int i = 1; i <= len; ++i)
            num ^= i;
        if (num)
            return num;
        else
        {
            if (has0) return len;
            else return 0;
        }
    }
};