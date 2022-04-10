#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // k 个一组翻转链表 递归 栈 记录节点值
class Solution {
public:
    ListNode* solve2(ListNode* head, int k) {
        ListNode* r = new ListNode();
        ListNode* c=r;
        ListNode* t;
        vector<ListNode*> s;
        while (1) { 
            t=head;
            while (s.size()<k&&t) {
                s.push_back(t),t=t->next;
            }
            // 不够 k 个
            if (s.size()<k) {
                c->next=head;
                break;
            }

            while (!s.empty()) {
                c->next = s.back();
                s.pop_back();
                c=c->next;
            }
            // 链接余下部分
            c->next=t;
            head=t;
        }

        return r->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v(k,0);
        ListNode * cur = head;
       for (int i = 0; cur ; i++) {
           if (i % k==0) {
               dfs(cur, 1, k, v);
           }
           cur = cur->next; 
       }
       return head;
    }
    bool dfs(ListNode * nod, int x, int k, vector<int> &v) {
        if (nod == nullptr)
            return false;
        v[x-1]=nod->val;
        if (x == k) {
            nod->val=v[k-x];
            return true;
        }
        bool ok =dfs(nod->next, x+1, k, v);
        if (ok) {
            nod->val=v[k-x];
        }
        return ok;
    }
};