#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
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
    int maxPathSum(TreeNode* root){
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }
    int maxPathDown(TreeNode* node, int& maxSum){
        if(node == nullptr) return 0;
        int left = max(0, maxPathDown(node->left, maxSum));
        int right = max(0, maxPathDown(node->right, maxSum));
        maxSum = max(maxSum, left + right + node->val);
        return node->val + max(left, right);
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
    TreeNode* root= createTree(vec);
    Solution s;
    cout << "Maximum path sum: " << s.maxPathSum(root) << endl;
}
