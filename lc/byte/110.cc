/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <math.h>
#include<algorithm>
#define NULL 0;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    bool ans;
public:
    int dfs(TreeNode* nod) {
        if (!nod)
            return 0;
        
        int l = dfs(nod->left);
        int r = dfs(nod->right);
        if (abs(l-r)>1)
            ans=false;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        dfs(root);
        return ans;
    }
};