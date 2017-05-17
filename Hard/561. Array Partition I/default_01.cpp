class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector <int> htable(20001, 0);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            htable[nums[i]+10000]++;
        }
        int isodd = 1;
        int valu = 0;
        for (size_t i = 0; i < htable.size();)
        {
            if (htable[i] > 0)
            {
                if (isodd)
                {
                    valu += i - 10000;
                    isodd = 0;
                }
                else
                {
                    isodd = 1;
                }
                htable[i]--;
            }
            else
                i++;
        }
        return valu;
    }
};

