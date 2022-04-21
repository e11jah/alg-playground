/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans =0;
public:
    // 同 lc 6073
    int maxPathSum(TreeNode* root) {
        if (root)
            ans=root->val;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* nod) {
        if (!nod)
            return 0;

        int l=dfs(nod->left),r=dfs(nod->right);
        // 子路径为负值则不走
        int t =max(nod->val, max(nod->val+l, nod->val+r));
        // 最大路径和可以为当前子树路径和
        ans=max(ans,max(t,nod->val+l+r));
        return t;
    }
};