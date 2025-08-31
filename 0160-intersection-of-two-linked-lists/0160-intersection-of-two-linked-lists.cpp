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
    // Notice that if list A and list B have the same length, this solution will terminate in no more than 1 traversal; 
    // if both lists have different lengths, this solution will terminate in no more than 2 traversals -- in the second traversal, 
    // swapping a and b synchronizes a and b before the end of the second traversal. By synchronizing a and b I mean both have the same 
    // remaining steps in the second traversal so that it's guaranteed for them to reach the first intersection node, or reach null at 
    // the same time.

    // You can prove that: say A length = a + c, B length = b + c, after switching pointer, pointer A will move another b + c steps, 
    // pointer B will move a + c more steps, since a + c + b + c = b + c + a + c, it does not matter what value c is. Pointer A and B 
    // must meet after a + c + b (b + c + a) steps. If c == 0, they meet at NULL.

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA;
        ListNode *p2=headB;
        
        if(p1==nullptr || p2==nullptr) return nullptr;

        while(p1!=p2) 
        {
            p1=p1->next;
            p2=p2->next;

            if(p1==p2) return p1;

            if(p1==nullptr) p1=headB;
            if(p2==nullptr) p2=headA;
        }    
        return p1;
    }
};