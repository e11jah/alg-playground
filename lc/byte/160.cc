

#define NULL 0;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 节点 map 或 双指针
        ListNode* a=headA;
        ListNode* b=headB;
        // if (interseted && lenA==lenB) 一次遍历
        // if (intersected && lenA!=lenB) lenA=x+common, lenB=y+common; 指针遍历 x+common+y 一定相交
        // if (!intersected) 遍历 lenA+lenB 同时到达 null
        while (a!=b) {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};