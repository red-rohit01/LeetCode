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
    // Let 'd' denote the initial distance between the slow and fast pointers inside the loop. At each step, the fast pointer moves 
    // ahead by two nodes while the slow pointer advances by one node.

    // The relative speed between them causes the gap to decrease by one node in each iteration (fast gains two nodes while slow gains 
    // one node). This continuous reduction ensures that the difference between their positions decreases steadily. Mathematically, if 
    // the fast pointer gains ground twice as fast as the slow pointer, the difference in their positions reduces by one node after each 
    // step. Consequently, this reduction in the distance between them continues until the difference becomes zero.

    // Moving the fast pointer by two steps prevents it from "jumping over" the slow pointer. If the fast pointer moved by more than two 
    // steps, it might skip over the slow pointer, and they might never meet, even in a cycle.

    // If the fast pointer moves 3 steps and slow pointer at 1 step, it is not guaranteed for both pointers to meet in cycles containing 
    // even number of nodes. If the slow pointer moved at 2 steps, however, the meeting would be guaranteed.

    // In general, if the hare moves at H steps, and tortoise moves at T steps, you are guaranteed to meet in a cycle iff H = T + 1.
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};