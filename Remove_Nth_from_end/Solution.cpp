#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {                                                        //添加一个哑节点
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* deleteNode=new ListNode(0,head);
        int length{0};
        ListNode* cur=deleteNode;
        while(head){
            ++length;
            head=head->next;
        }
        for(int i=1;i<length-n+1;++i){
            cur=cur->next;
        }
        cur->next=cur->next->next;
        ListNode* result=deleteNode->next;
        return result;
    }
};

int main(){
    int size{0};
    int val{0};
    int n{0};
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
    cout<<"please enter n:\n";
    cin>>n;
    Solution s1;
    ListNode* deletedList=s1.removeNthFromEnd(head,n);
    ListNode* now=deletedList;
    while(now){
        cout << now->val << ",";
        now = now->next;
    }
    cout << endl;
    while(deletedList){
        ListNode* temp=deletedList;
        temp=temp->next;
        delete temp;
    }
}