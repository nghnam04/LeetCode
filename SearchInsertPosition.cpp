#include<iostream>
#include<vector>

using namespace std;
/*
Hàm tìm và trả về vị trí của targer nhập vào trong mảng nums
Nếu không tìm thấy target trong mảng nums thì trả về vị trí target đáng ra sẽ xuất hiện theo thứ tự
*/class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size();
        int mid;
        if(target>nums[high-1]){
            return high;
        }
        while(low<=high){
              mid=(low+high)/2;
            if(nums[mid]==target){  
                return mid;
            }
          
            if(target<nums[mid]){     
            high=mid-1;    
            }else{
            low=mid+1;        
            }
          
        }
         return  low;   
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    
    // Test cases
    cout << "Test Case 1: Expected: 2, Output: " << sol.searchInsert(nums, 5) << endl;  // Target found in array
    cout << "Test Case 2: Expected: 1, Output: " << sol.searchInsert(nums, 2) << endl;  // Target not found, should be inserted at index 1
    cout << "Test Case 3: Expected: 4, Output: " << sol.searchInsert(nums, 7) << endl;  // Target greater than all elements, should be inserted at the end
    cout << "Test Case 4: Expected: 0, Output: " << sol.searchInsert(nums, 0) << endl;  // Target less than all elements, should be inserted at the beginning

    return 0;
}