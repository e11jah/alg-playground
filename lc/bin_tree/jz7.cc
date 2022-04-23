/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int n;
public:
    // 重建二叉树
    TreeNode* reConstructBinaryTree(vector<int> & pre,vector<int>& vin) {
        n = vin.size();
        if (n < 1) return NULL;
        return dfs(0,0,n,pre,vin);
    }
    TreeNode* dfs(int pl, int vl, int len, vector<int> & p, vector<int> & v) {
         // 第一个为根
        TreeNode* nod = new TreeNode(p[pl]);
        // 找根节点在 vin 的下标
        int vpos;
        for(int i = vl; i < vl+len; i++)
            if (v[i]==p[pl]) {
                vpos=i;
                break;
            }
        
        int llen = vpos-vl, rlen=vl+len-1-vpos;
//         printf("%d %d %d %d %d\n", pl, vl, len, llen, rlen);
        if (llen>0)
            nod->left = dfs(pl+1,vl,llen,p,v);
        if (rlen>0)
            // pre 的起点从前面开始计算
            nod->right = dfs(pl+1+llen,vpos+1,rlen,p,v);
        return nod;
    }
};