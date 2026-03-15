#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution{
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* p = root;
        while(p->right != nullptr){
            p = p->right;
        }
        p->right = temp;
    }
};

TreeNode* createTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main(){
    int size{0},val{0};
    vector<int> vec;
    cout << "Enter the number of nodes in the tree: ";
    cin >> size;
    cout << "Enter the values of the nodes (use -1 for null nodes): ";
    for(int i = 0; i < size; i++){
        cout << "Node " << i + 1 << ": ";
        cin >> val;
        vec.push_back(val);
    }
    TreeNode* root = createTree(vec);
    Solution s;
    s.flatten(root);
    cout << "The flattened tree (preorder traversal): ";
    TreeNode* current = root;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
}