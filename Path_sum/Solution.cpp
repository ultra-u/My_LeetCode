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

class Solution{             //双重递归，外层递归遍历每个节点，内层递归计算以当前节点为起点的路径和
public:
    int pathSum(TreeNode* root, int targetSum){
        if(root == nullptr) return 0;
        return pathSumFrom(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int pathSumFrom(TreeNode* node, int targetSum){
        if(node == nullptr) return 0;
        int count = 0;
        if(node->val == targetSum) count++;
        count += pathSumFrom(node->left, targetSum - node->val);
        count += pathSumFrom(node->right, targetSum - node->val);
        return count;
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
    int size{0}, val{0}, targetSum{0};
    vector<int> vec;
    cout << "Enter the number of nodes in the tree: ";
    cin >> size;
    cout << "Enter the values of the nodes (use -1 for null nodes): ";
    for(int i = 0; i < size; i++){
        cout<<"Node " << i + 1 << ": ";
        cin >> val;
        vec.push_back(val);
    }
    cout << "Enter the target sum: ";
    cin >> targetSum;
    TreeNode* root = createTree(vec);
    Solution s;
    int result = s.pathSum(root, targetSum);
    cout << "Number of paths that sum to " << targetSum << ": " << result << endl;
}

