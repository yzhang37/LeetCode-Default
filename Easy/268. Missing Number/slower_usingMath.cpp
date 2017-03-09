class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
            sum += nums[i];
        return (len+1)*len/2-sum;
    }
};