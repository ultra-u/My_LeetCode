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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n=lists.size();
        while(n>1){
            int k=(n+1)/2;
            for(int i=0;i<n/2;i++){
                lists[i]=merge(lists[i],lists[i+k]);
            }
            n=k;
        }
        return lists[0];
    }
};

int main(){
    int k{0},size{0},val{0};
    cout<<"please enter number of lists:\n";
    cin>>k;
    vector<ListNode*> lists(k,nullptr);
    for (int i = 0; i < k; i++) {
        cout << "please enter size of list " << i + 1 << ":\n";
        cin >> size;
        cout << "please enter values of list " << i + 1 << ":\n";
        cin >> val;
        ListNode* head = new ListNode(val);
        ListNode* current = head;
        for (int j = 1; j < size; j++) {
            cout << "please enter values of list " << i + 1 << ":\n";
            cin >> val;  
            current->next = new ListNode(val);  
            current = current->next;  
        }       
        lists[i] = head;
    }
    Solution solution;
    ListNode* mergedHead=solution.mergeKLists(lists);
    cout<<"Merged list values:\n";
    while(mergedHead!=nullptr){
        cout<<mergedHead->val<<" ";
        mergedHead=mergedHead->next;
    }
    cout<<endl;
    return 0;
}