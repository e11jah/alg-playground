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
public:
    int count(TreeNode* nod) {
        if (!nod)
            return 0;
        return 1+count(nod->left)+count(nod->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        int l = count(root->left);
        if (l==k-1)
            return root->val;

        if (l<k-1) 
            // 左子树 + 根 去掉了 k-l-1 个元素
            return kthSmallest(root->right, k-l-1);
        else
            return kthSmallest(root->left, k);
    }
    
};