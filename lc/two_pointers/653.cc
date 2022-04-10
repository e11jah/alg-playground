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
    void inorder(TreeNode* n, vector<int> &v) {
        if (!n)
            return;
        inorder(n->left, v);
        v.push_back(n->val);
        inorder(n->right, v);
    }
 
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        int l = 0, r = v.size()-1, t;
        // 中序 BST + 双指针
        while (l<r) {
            t=v[l]+v[r];
            if (t==k)
                return true;
            if (t<k)
                l++;
            else
                r--;
        } 
        return false;
    }
};