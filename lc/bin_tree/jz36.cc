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
    TreeNode* head=NULL;
    TreeNode* prev=NULL;
public:
    TreeNode* Convert(TreeNode* p) {
        if (!p)
            return p;
        traversal(p);
        return head;
    }
    void traversal(TreeNode* n) {
        if (!n)
            return;
        if (!n->left&&!head) {
            head=n,prev=n;
            traversal(n->right);
            return;
        }
        
        traversal(n->left);
        n->left=prev;
        prev->right=n;
        prev=n;
        traversal(n->right);
    }
};