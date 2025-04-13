#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            ListNode* pre=nullptr;                              //pre指针用于前接住curr指针的next，达到反向的效果
            ListNode* curr=head;                                //curr指向head,用于后续的移位遍历
            while(curr){
                ListNode* next=curr->next;                      //建立一个next指针用于接收curr->next,这样后续curr能够持续往右遍历
                curr->next=pre;                                 //这里起到反转链表的效果
                pre=curr;                                       
                curr=next;
            }
            return pre;
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
    ListNode* reversedHead=s1.reverseList(head);
    ListNode* now = reversedHead;
    while(now){                                     //打印反转后的链表
        cout << now->val << ",";
        now = now->next;
    }
    cout << endl;
    while(reversedHead){                             //释放内存
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
}