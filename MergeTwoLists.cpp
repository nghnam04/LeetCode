#include<iostream>
using namespace std;
  typedef struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  } ListNode;

  //Hàm trộn 2 lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1; 
        ListNode* temp2 = list2;
        if(list1 == NULL) return list2; //Nếu 1 trong 2 list rỗng thì trả về list còn lại
        if(list2 == NULL) return list1;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

//Hàm tạo list
ListNode* createList(int arr[], int size) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int i = 0; i < size; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (!head) {
            head = newNode; //Nếu con trỏ head chưa có gtri thì head là node mới thêm vào
        } else {
            tail->next = newNode; //Nếu đã có head thì các node mới được tạo nối tiếp vào sau đuôi
        }
        tail = newNode; //Gán đuôi là node vừa tạo
    }
    return head;
}

// Hàm ỉn ra list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    int arr1[] = {1, 2, 4, 5, 7, 9};
    int arr2[] = {1, 2, 6, 9, 11};
    ListNode* l1 = createList(arr1, 6);
    ListNode* l2 = createList(arr2, 5);

    Solution sol;
    ListNode* result = sol.mergeTwoLists(l1, l2);
    printList(result);

    return 0;
}