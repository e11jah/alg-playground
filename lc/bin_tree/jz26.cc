/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* p1, TreeNode* p2) {
        // 空树不是任意树的子结构
        if (!p1||!p2)
            return false;
        return dfs(p1,p2)||HasSubtree(p1->left, p2) || HasSubtree(p1->right, p2);
    }
    // dfs 仅在 a,b 都不空时开始比较
    bool dfs(TreeNode* a, TreeNode* b) {
        // 比较到右树空则匹配成功
        if (!b) return true;
        if (!a) return false;
        return a->val==b->val&&dfs(a->left,b->left)&&dfs(a->right,b->right);
    }
};