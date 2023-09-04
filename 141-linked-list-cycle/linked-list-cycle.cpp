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
    bool hasCycle(ListNode *head){
       
       if(head== NULL || head->next==NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) break;
        }
        if(slow != fast) return false;

        ListNode* ptr = head;

        while(ptr != slow){
            ptr = ptr->next;
            slow = slow->next;
        }
        return ptr;
    }

  /*-----brute force space - O(n)

    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        set<ListNode *> s;
        while( ptr != NULL) {
            s.insert(ptr);
            ptr = ptr->next;

            if(s.find(ptr) != s.end()) return true;
        }
        return false;
    }*/
};