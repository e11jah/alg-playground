/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        return solve(pHead, NULL);
    }
    ListNode* solve(ListNode* h, ListNode* nh) {
        if (!h) return nh;
        ListNode* nex=h->next;
        h->next=nh;
        return solve(nex,h);
    }
    ListNode* solve2(ListNode* pHead) {
        ListNode* r = new ListNode(0);
        vector<ListNode*> v;
        while (pHead) v.push_back(pHead),pHead=pHead->next;
        pHead=r;
        while (!v.empty()) {
            pHead->next = v.back();
            v.pop_back(), pHead=pHead->next;
        }
        pHead->next=NULL;
        return r->next;
    }
};