#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {                                                        //采用双指针来确定有无交点
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA; // pA 和 pB 在这里都指向交点，或者都是 NULL
    }
};

int main(){
    int size_a{0},size_b{0};
    int val{0};
    cout<<"please enter size_a:\n";
    cin>>size_a;
    cout<<"please enter size_b:\n";
    cin>>size_b;
    cout<<"please enter first_val_a:\n";
    cin>>val;
    ListNode* headA=new ListNode(val);
    ListNode* curr_a=headA;
    for(int i=0;i<size_a-1;i++){
        cout<<"please enter val:\n";
        cin>>val;
        curr_a->next=new ListNode(val);
        curr_a=curr_a->next;
    }
    curr_a->next=nullptr;
    cout<<"please enter first_val_b:\n";
    cin>>val;
    ListNode* headB=new ListNode(val);
    ListNode* curr_b=headB;
    for(int j=0;j<size_b-1;j++){
        cout<<"please enter val:\n";
        cin>>val;
        curr_b->next=new ListNode(val);
        curr_b=curr_b->next;
    }
    curr_b->next=nullptr;
    Solution s1;
    ListNode *intersection = s1.getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersected at " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    //释放内存
    while (headA) {
        ListNode *temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB) {
        ListNode *temp = headB;
        headB = headB->next;
        delete temp;
    }

}