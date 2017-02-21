class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xval = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            xval ^= nums[i];
        }
        xval &= -xval;
        
        vector<int>res(2,0);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & xval)
                res[0] ^= nums[i];
            else
                res[1] ^= nums[i];
        }
        return res;
    }
};