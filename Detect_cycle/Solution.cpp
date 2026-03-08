#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode *ptr1 = head, *ptr2 = slow;
                while(ptr1 != ptr2){
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return NULL;
    }   
};

int main(){
    int size{0}, val{0}, pos{0};
    cout<<"please enter size:\n";
    cin>>size;  
    cout<<"please enter first val:\n";
    cin>>val;
    ListNode* head=new ListNode(val);
    ListNode* curr=head;
    ListNode* cycleEntry = nullptr;
    for(int i=0;i<size-1;i++){
        cout<<"please enter val:\n";
        cin>>val;
        curr->next=new ListNode(val);
        curr=curr->next;
        if(i == pos - 1){
            cycleEntry = curr; // Mark the node where the cycle should start
        }
    }
    cout<<"please enter pos:\n";
    cin>>pos;
    if(cycleEntry != nullptr){
        curr->next = cycleEntry;
    }
    Solution s1;
    ListNode* cycleStart = s1.detectCycle(head);
    if(cycleStart){
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
}