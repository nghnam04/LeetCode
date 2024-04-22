//Định nghĩa một node của cây
 typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;
 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
//Hàm xét một cây binary search tree có cân bằng hay không
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Cây rỗng là cây cân bằng
        if (root == NULL)  return true;
		if (Height(root) == -1)  return false;
		return true;
	}

	int Height(TreeNode* root) {
		if (root == NULL)  return 0;
		int leftHeight = Height(root->left);
		int rightHight = Height(root->right);
        //Nếu chiều cao của chênh lệch 2 nhánh của một cây lớn hơn 1 thì cây là không cân bằng
		if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)  return -1;
        //Chiều cao của cây bằng chiều cao của cây con (phải hoặc trái) cao hơn +1 là nút gốc
		return max(leftHeight, rightHight) + 1;
    }
}; 

// Hàm để thêm nút vào BST theo cách đơn giản
TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insertIntoBST(root->left, value);
    } else {
        root->right = insertIntoBST(root->right, value);
    }
    return root;
}

// Hàm tạo cây từ danh sách các giá trị
TreeNode* createTree(const vector<int>& values) {
    TreeNode* root = NULL;
    for (int value : values) {
        root = insertIntoBST(root, value);
    }
    return root;
}

int main() {
    Solution solution;
    vector<int> values1 = {10, 7, 6 ,9, 8}; // Cây không cân bằng
    vector<int> values2 = {10, 7, 6, 9, 12}; // Cây cân bằng
    TreeNode* root1 = createTree(values1);
    TreeNode* root2 = createTree(values2);
    
    cout << "Cây 1 có cân bằng không? " << solution.isBalanced(root1) << endl;
    cout << "Cây 2 có cân bằng không? " << solution.isBalanced(root2) << endl;
    return 0;
}