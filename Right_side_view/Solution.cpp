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
     vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        vector<TreeNode*> q{root};
        while(!q.empty()){
            int n = q.size();
            res.push_back(q[0]->val);
            for(int i = 0; i < n; i++){
                TreeNode* node = q[i];
                if(node->right) q.push_back(node->right);
                if(node->left) q.push_back(node->left);
            }
            q.erase(q.begin(), q.begin() + n);
        }
        return res;
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
    int size{0};
    cout << "Enter the number of nodes in the tree: ";
    cin >> size;
    vector<int> nodes(size);
    cout << "Enter the node values (use -1 for null nodes): ";
    for(int i = 0; i < size; i++){
        cout << "Node " << i << ": \n";
        cin >> nodes[i];
    }
    TreeNode* root = createTree(nodes);
    Solution s;
    vector<int> rightView = s.rightSideView(root);
    
    cout << "Right side view of the tree: [";
    for (size_t i = 0; i < rightView.size(); i++) {
        cout << rightView[i];
        if (i < rightView.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}