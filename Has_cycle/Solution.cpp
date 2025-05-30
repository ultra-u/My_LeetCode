#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {                                            //使用快慢指针,慢指针每次走一格，快指针每次走两格
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=fast){
            if(fast==nullptr||fast->next==nullptr){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};

int main(){
    int size{0};
    int val{0};
    cout<<"please enter size:\n";
    cin>>size;
    cout<<"please enter first val:\n";
    cin>>val;
    ListNode* head=new ListNode(val);
    ListNode* curr=head;
    for(int i=0;i<size-1;i++){
        cout<<"please enter val:\n";
        cin>>val;
        curr->next=new ListNode(val);
        curr=curr->next;
    }
    curr->next=nullptr;
    Solution s1;
    cout<<"Whether there are cycle in the linked list: "<<s1.hasCycle(head);
}