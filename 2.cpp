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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode helper1(0), helper2(0); 
        helper1.next = l1; 
        helper2.next = l2; 
        
        ListNode* curr1 = &helper1; 
        ListNode* curr2 = &helper2; 
        
        ListNode helper3(0); 
        helper3.next = NULL; 
        ListNode* curr3 = &helper3; 
        int extraSum = 0; 
        while(curr1->next && curr2->next)
        {
            int sum = curr1->next->val +curr2->next->val +extraSum; 
            
            if(sum > 9)
            {
                curr3->next = new ListNode(sum%10); 
                extraSum = 1; 
            }
            else
            {
                curr3 -> next = new ListNode(sum); 
                extraSum = 0; 
            }
            
            curr1 = curr1->next; 
            curr2 = curr2->next; 
            curr3 = curr3->next; 
        }
        
        if(!curr1->next && !curr2->next)
        {
            if(extraSum)
            {
                curr3->next = new ListNode(1); 
            }
        }
        else
        {
        
        ListNode* curr = NULL; 
        if(!curr1->next && curr2 -> next)
            curr = curr2->next; 
        if(curr1 -> next && !curr2 -> next)
            curr = curr1->next; 
            
        
            while(curr)
            {
                int sum = curr->val + extraSum; 
                if(sum >9)
                {
                    curr3->next = new ListNode(sum %10); 
                    extraSum = 1; 
                }
                else
                    {
                        curr3->next = new ListNode(sum %10); 
                     extraSum = 0; 
                    }
                    
                    curr = curr -> next; 
                    curr3 = curr3->next; 
            }
            if(extraSum)
            {
                curr3->next = new ListNode(1); 
            }
        }
 
        return helper3.next; 
        
    }
};
