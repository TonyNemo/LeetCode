/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// beats 24.8% 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* p = result;
        int c = 0;
        while(l1 != NULL && l2 != NULL){
        	p->val += (l1->val + l2->val);
        	c = p->val/10;
        	p->val%=10;
        	l1 = l1->next;
        	l2 = l2->next;
        	if(l1 == NULL && l2 == NULL){
        	    if(c==1){
        	        p->next = new ListNode(1);
                	p = p->next;
        	    }
        	    break;
        	}
        	else if(l1 == NULL || l2 == NULL){
        	    p->next = new ListNode(c);
        	    p = p->next;
        	    break;
        	}
        	p->next = new ListNode(c);
        	p = p->next;
        }
        while(l1 != NULL){
        	p->val += l1->val;
        	l1 = l1->next;
        	c = p->val/10;
        	p->val%=10;
        	if(c==1){
        	    p->next = new ListNode(1);
        	    p = p->next;
        	    if(l1 == NULL) break;
        	}
        	else{
        	    if(l1 == NULL) break;
            	p->next = new ListNode(0);
                p = p->next;
        	}
        }
        while(l2 != NULL){
        	p->val += l2->val;
        	l2 = l2->next;
        	c = p->val/10;
        	p->val%=10;
        	if(c==1){
        	    p->next = new ListNode(1);
        	    p = p->next;
        	    if(l2 == NULL) break;
        	}
             else{
        	    if(l2 == NULL) break;
            	p->next = new ListNode(0);
                p = p->next;
        	}
        }
        return result;
    }
};