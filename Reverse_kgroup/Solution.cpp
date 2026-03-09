#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head,int k){
        if(head == nullptr) return nullptr;
        ListNode* curr = head;
        int count = 0;
        while(curr != nullptr && count < k){
            curr = curr->next;
            count++;
        }
        if(count == k){
            ListNode* reversedHead = reverseKGroup(curr, k);
            while(count > 0){
                ListNode* temp = head->next;
                head->next = reversedHead;
                reversedHead = head;
                head = temp;
                count--;
            }
            return reversedHead;
        } else {
            return head;
        }
    }
};

int main(){
    int size{0},val{0},k{0};
    cout<<"please enter size of list:\n";
    cin>>size;
    cout<<"please enter first val of list:\n";
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
    cout<<"please enter k:\n";
    cin>>k;
    Solution s1;
    ListNode* reversedHead = s1.reverseKGroup(head, k);
    cout<<"reversed list:\n";
    curr = reversedHead;
    while(curr != nullptr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
}