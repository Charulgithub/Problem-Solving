/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        set<ListNode *> s;
        while( ptr != NULL) {
            s.insert(ptr);
            ptr = ptr->next;

            if(s.find(ptr) != s.end()) return true;
        }
        return false;
    }
};