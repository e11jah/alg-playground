/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <map>
#include <queue>

using namespace std;
#define NULL 0;
struct TreeNode {
    int val;
    TreeNode *left;
   TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        if (!p)
            return q;
        if (!q)
            return p;

        // 查询父节点
        map<TreeNode*,TreeNode*> par;
        queue<TreeNode*> qq;
        qq.push(root);
        par[root]=NULL;

        TreeNode* t;
        int s, lv=1;
        while (!qq.empty()) {
            s = qq.size();
            while (s--) {
                t = qq.front();
                qq.pop();
                
                if (t->left)
                    qq.push(t->left), par[t->left]=t;
                if (t->right)
                    qq.push(t->right), par[t->right]=t;
            }
            if (par.count(p)&&par.count(q)) {
                break;
            }
            lv++;
        }


        // 双链表求相交节点问题
        TreeNode* cp = p;
        TreeNode* cq=q;
        // if (interseted && lenA==lenB) 一次遍历
        // if (intersected && lenA!=lenB) lenA=x+common, lenB=y+common; 指针遍历 x+common+y 一定相交
        // if (!intersected) 遍历 lenA+lenB 同时到达 null
        while (cp!=cq) {
            cp = cp == NULL ? q : par[cp];
            cq = cq == NULL ? p : par[cq];
        }
        return cp;
    }

};
