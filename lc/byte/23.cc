/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *r = new ListNode(-1);
        ListNode *c = r;
        // priority_queue<ListNode*, vector<ListNode*>, gt<ListNode*>> q;
        vector<ListNode *> q;
        for (ListNode *x : lists)
        {
            while (x != nullptr)
                q.push_back(x), x = x->next;
        }
        sort(q.begin(), q.end(), [](ListNode *l, ListNode *r)
             { return l->val < r->val; });
        for (int i = 0; i < q.size(); i++)
        {
            c->next = q[i], c = c->next;
        }
        c->next = nullptr;
        return r->next;
    }
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *solve2(vector<ListNode *> &lists)
    {
        // custom comparator
        priority_queue<ListNode *, vector<ListNode *>, comp> q;
        // 优先队列法, 同上，推进所有节点 pop
        return nullptr;
    }
};