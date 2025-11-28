/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // This solution is based on Striver's solution.The idea is creating 7` between 7 and 13 and 7 points to 7` and 7` points to 13. similarily for other nodes. Then, join random pointer between those (`) correspondingly.
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* curr=head;
        while(curr)
        {
            Node* next=curr->next;
            curr->next=new Node(curr->val,next,NULL);
            curr=next;
        }

        // 7-->7'__13-->13'__11-->11'__10-->10'__1-->1'-->null [This one is the connection with 'next' pointer and __ denotes no connection]

        curr=head;                                  
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;       // Randomness connection in ` nodes.   7' connected to 1' and so on for others
            }
            curr=curr->next->next;
        }

        // Now all the random pointers are connected in the returning list
        // Now, we'll connect the 'next' pointer in the returning list
        curr=head;
        Node* copyhead=head->next;
        while(curr)
        {
            Node* nxt=curr->next->next;
            Node* copy=curr->next;
            curr->next=nxt;

            if(nxt) copy->next=nxt->next;
            curr=nxt;
        }
        return copyhead;
    }
};