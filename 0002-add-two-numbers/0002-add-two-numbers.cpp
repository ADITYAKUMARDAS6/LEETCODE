
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
class Solution {    
    void insertAtTail(ListNode*& head, ListNode*& tail, int data) {
        ListNode* node = new ListNode(data);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    ListNode* addNodes(ListNode*&first, ListNode*&second){ 
        
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        int carry=0;
        
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL){
                val1=first->val;
            }
            int val2=0;
            if(second!=NULL){
                val2=second->val;
            }
            int sum=carry+val1+val2;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            
            if(first!=NULL)first=first->next;
            if(second!=NULL)second=second->next;
        }
        return ansHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {       
        ListNode* ans=addNodes(first,second);
        return ans;

    }    
};