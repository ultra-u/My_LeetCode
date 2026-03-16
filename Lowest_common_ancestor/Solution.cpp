#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr){
            return root;
        }
        return left != nullptr ? left : right;
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
    int size{0}, val{0};
    vector<int> vec;
    cout << "Enter the number of nodes in the tree: ";
    cin >> size;
    cout << "Enter the values of the nodes (use -1 for null nodes): ";
    for(int i = 0; i < size; i++){
        cout<<"Node " << i + 1 << ": ";
        cin >> val;
        vec.push_back(val);
    }
    TreeNode* root = createTree(vec);
    int pVal{0}, qVal{0};
    cout << "Enter the value of node p: ";
    cin >> pVal;
    cout << "Enter the value of node q: ";
    cin >> qVal;
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    // Function to find nodes p and q in the tree
    function<void(TreeNode*)> findNodes = [&](TreeNode* node) {
        if (node == nullptr) return;
        if (node->val == pVal) p = node;
        if (node->val == qVal) q = node;
        findNodes(node->left);
        findNodes(node->right);
    };
    findNodes(root);
    
    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << pVal << " and " << qVal << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    
    return 0;
}


