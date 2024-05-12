#include<iostream>
using namespace std;

//Cấu trúc một Node của cây
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
//Hàm kiểm tra xem 2 cây có giống nhau hay không
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if(!p && !q) //Nếu hai cây rỗng thì giống nhau
        return 1;

       else if(!p || !q) //Nếu một trong hai cây rỗng thì khác nhau
       return 0;

       return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
int main(){
    Solution sl;
 // Tạo cây thứ nhất
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Tạo cây thứ hai giống hệt cây thứ nhất
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Tạo cây thứ ba khác
    TreeNode *tree3 = new TreeNode(1);
    tree3->left = new TreeNode(2);
    tree3->right = new TreeNode(4); // Giá trị khác ở nút này

    // Kiểm thử
    cout << "Tree 1 and Tree 2 are the same: " << (sl.isSameTree(tree1, tree2) ? "Yes" : "No") << endl;
    cout << "Tree 1 and Tree 3 are the same: " << (sl.isSameTree(tree1, tree3) ? "Yes" : "No") << endl;

    // Xóa bộ nhớ
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->left;
    delete tree3->right;
    delete tree3;

    return 0;
}