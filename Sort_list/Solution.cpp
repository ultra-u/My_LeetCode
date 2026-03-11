#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution{
public:
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode();
        ListNode* current=dummy;
        while(left!=nullptr&&right!=nullptr){
            if(left->val<right->val){
                current->next=left;
                left=left->next;
            }else{
                current->next=right;
                right=right->next;
            }
            current=current->next;
        }
        if(left!=nullptr) current->next=left;
        if(right!=nullptr) current->next=right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
        return merge(left,right);
    }
};

int main(){
    int size{0},val{0};
    cout<<"please enter size of list:\n";
    cin>>size;
    cout<<"please enter values of list:\n";
    cin>>val;
    ListNode* head=new ListNode();
    ListNode* current=head;
    for(int i=1;i<size;i++){
        current->val=val;
        current->next=new ListNode();
        current=current->next;
        cout<<"please enter values of list:\n";
        cin>>val;
    }   
    current->val=val;
    Solution s;
    ListNode* sortedHead=s.sortList(head);
    cout<<"The sorted list is:\n";
    current=sortedHead;
    while(current!=nullptr){
        cout<<current->val<<" ";
        current=current->next;
    }
}