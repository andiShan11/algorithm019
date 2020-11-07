class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* ans=temp;
        while(l1&&l2){
            if(l1->val<l2->val){
                temp->next=new ListNode(l1->val);
                temp=temp->next;
                l1=l1->next;
            }
            else{
                temp->next=new ListNode(l2->val);
                temp=temp->next;
                l2=l2->next;
            }
        }
        while(l1){
            temp->next=new ListNode(l1->val);
            temp=temp->next;
            l1=l1->next;
        }
        while(l2){
             temp->next=new ListNode(l2->val);
             temp=temp->next;
             l2=l2->next;
        }
        return ans->next;
    }
};
