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
    int ans=0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* nod) {
        if (!nod)
            return 0;

        int l = nod->left?1+dfs(nod->left):0, r=nod->right?1+dfs(nod->right):0;
        ans=max(ans,l+r);

        return max(l,r);
    }
};