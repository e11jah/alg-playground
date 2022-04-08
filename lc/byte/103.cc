#include <vector>
#include <queue>
using namespace std;
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 二叉树的锯齿形层序遍历 bfs
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> t;
        queue<TreeNode*> q;
        q.push(root);
        int n, seq=0;
        TreeNode * x;
        while (!q.empty()) {
            n=q.size();
            t.resize(n);
            while (n--) {
                x=q.front(), q.pop();
                // 索引赋值
                t[seq? n : t.size()-n-1]=x->val;

                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            ans.push_back(t);
            seq ^=1;
        }
        return ans;
    }
};