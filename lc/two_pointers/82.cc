 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 // 删除排序链表中的重复元素 II
 // 删除所有重复数字的节点
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;

        ListNode* r = new ListNode(0, head);
        ListNode* cur = r;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val==x)
                    cur->next=cur->next->next;
            } else 
                cur=cur->next;
        }
        return r->next;

    }
};