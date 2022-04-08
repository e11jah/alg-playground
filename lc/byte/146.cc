#include <map>
#include <iostream>
using namespace std;
static const auto io_sync_off = []()
{
    // turn off sync
    ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(nullptr);
    return nullptr;
}();
struct Node {
    int key, val;
    Node* next;
    Node* prev;
    Node():key(0),val(0),next(nullptr),prev(nullptr){}
    Node(int k, int x):key(k),val(x),next(nullptr),prev(nullptr){}
    ~Node() {
        next=nullptr;
        prev=nullptr;
    }
};
// lru map + 双向链表
class LRUCache {

    map<int,Node*> mp;
    int len,cap;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity):len(0),cap(capacity) {
        head=new Node(),tail=new Node();
        head->next=tail,tail->prev=head;
    }
    
    int get(int key) {
        if (!mp.count(key))
            return -1;
        Node* n = mp[key];
        if (n->next)
            n->next->prev = n->prev;
        if (n->prev)
            n->prev->next = n->next;

        n->next=head->next,n->prev=head;
        head->next->prev=n;
        head->next=n;
        return n->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            mp[key]->val=value;
            get(key);
            return;
        }
        if (len==cap) {
            Node * n = tail->prev;
            n->prev->next=tail;
            tail->prev=n->prev;
            mp.erase(n->key);
            // delete n;
            len--;
        }
        Node * n = new Node(key, value);
        mp[key]=n;
        len++;
        get(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */