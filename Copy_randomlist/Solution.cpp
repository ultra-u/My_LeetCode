#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }    
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        // 第一步：创建所有新节点，并建立映射关系
        unordered_map<Node*, Node*> nodeMap;
        Node* cur = head;
        
        while(cur != NULL) {
            nodeMap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        
        // 第二步：连接next和random指针
        cur = head;
        while(cur != NULL) {
            nodeMap[cur]->next = nodeMap[cur->next];
            nodeMap[cur]->random = nodeMap[cur->random];
            cur = cur->next;
        }
        
        return nodeMap[head];
    }
};

int main(){
    int size{0},val{0},random{0};
    cout<<"size: ";
    cin>>size;
    vector<Node*> nodes(size);
    for(int i=0;i<size;i++){
        cout<<"val: ";
        cin>>val;
        cout<<"random: ";
        cin>>random;
        nodes[i] = new Node(val);
        if(i>0) nodes[i-1]->next = nodes[i];
        if(random != -1) nodes[i]->random = nodes[random];
    }
    Solution s;
    Node* newHead = s.copyRandomList(nodes[0]);
    Node* cur = newHead;
    while(cur != NULL){
        cout<<"val: "<<cur->val<<" random: "<<(cur->random != NULL ? cur->random->val : -1)<<endl;
        cur = cur->next;
    }
}