class Solution {
public:
    vector < vector < int > > matrixReshape(vector < vector < int > >& nums, int r, int c) {
        size_t count = nums.size() * nums[0].size(), n = nums[0].size();
        if (count != r * c)
            return nums;
        vector < vector < int > > res(r, vector <int>(c, 0));
        for (size_t idx = 0; idx < count; ++idx)
            res[idx/c][idx%c] = nums[idx/n][idx%n];
        return res;
    }
};

