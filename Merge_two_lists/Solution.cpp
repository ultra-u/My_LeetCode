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

class Solution{               //递归，两个链表头部值较小的一个节点与剩下元素的merge操作结果合并
public: 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main(){
    int size1{0}, size2{0}, val{0};
    cout<<"please enter size of first list:\n";
    cin>>size1;
    cout<<"please enter first val of first list:\n";
    cin>>val;
    ListNode* head1=new ListNode(val);
    ListNode* curr1=head1;
    for(int i=0;i<size1-1;i++){
        cout<<"please enter val:\n";
        cin>>val;
        curr1->next=new ListNode(val);
        curr1=curr1->next;
    }
    curr1->next=nullptr;

    cout<<"please enter size of second list:\n";
    cin>>size2;
    cout<<"please enter first val of second list:\n";
    cin>>val;
    ListNode* head2=new ListNode(val);
    ListNode* curr2=head2;
    for(int i=0;i<size2-1;i++){
        cout<<"please enter val:\n";
        cin>>val;
        curr2->next=new ListNode(val);
        curr2=curr2->next;
    }
    curr2->next=nullptr;

    Solution s1;
    ListNode* mergedHead = s1.mergeTwoLists(head1, head2);
    
    cout << "Merged list: ";
    while(mergedHead){
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;
    return 0;
}