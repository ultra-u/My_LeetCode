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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        vector<int> temp = v;
        reverse(temp.begin(), temp.end());
        return temp == v;
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
    bool isPalin = s1.isPalindrome(head);
    if(isPalin){
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
}