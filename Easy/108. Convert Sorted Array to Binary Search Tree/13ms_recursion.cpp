class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return mergeInsert(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* mergeInsert(vector<int>& nums, int b, int e)
    {
        if (e < b) return NULL;
        int m = (b + e + 1) / 2;
        TreeNode *mid = new TreeNode(nums[m]);
        mid -> left = mergeInsert(nums, b, m-1);
        mid -> right = mergeInsert(nums, m+1, e);
        return mid;
    }
};