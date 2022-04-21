/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {

public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode)
            return pNode;
        TreeLinkNode* ans;
        TreeLinkNode* cur=pNode->right;
        // 有右子树的话，是右子树的第一个叶子
        while (cur) {
            if (!cur->left)
                return cur;
            cur = cur->left;
        }
        if (!pNode->next) return NULL;
        // 当前节点不是根或者树只有左子树
        while (pNode) {
            // 检查是否是父节点的左子
            cur = pNode->next;
            // 按照中序, 左子之后是父节点
            if (cur&&cur->left==pNode)
                return cur;
            pNode=pNode->next;
        }
        return pNode;
    }
};