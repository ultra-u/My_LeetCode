#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {                                                            //递归
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)   return head;
        ListNode* one=head;
        ListNode* two=one->next;
        ListNode* three=two->next;
        two->next=one;
        one->next=swapPairs(three);
        return two;
    }
    friend ostream& operator<<(ostream& out,const ListNode* result);
};

ostream& operator<<(ostream& out,const ListNode* result){
    out << "[";
    while (result != nullptr) {
        out << result->val;
        if (result->next != nullptr) out << ", ";
        result = result->next;
    }
    out << "]";
    return out;
}

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
    cout<<"after change: "<<s1.swapPairs(head);
}