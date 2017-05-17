class Solution {
public:
    vector < vector < int > > matrixReshape(vector < vector < int > >& nums, int r, int c) {
        int count = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            count += nums[i].size();
        if (count != r * c)
            return nums;
        vector < vector < int > > res(r, vector <int>(c, 0));
        
        size_t idx = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            for (vector <int>::iterator b = nums[i].begin();
                 b != nums[i].end();
                 b++, idx++)
                res[idx/c][idx%c] = *b;
        return res;
    }
};
