#include<iostream>
#include<vector>
using namespace std;
//Hàm tìm số xuất hiện 1 lần trong mảng các số xuất hiện 2 lần
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x; //Thực hiện phép toán XOR giữa x và 0 (x^0=x; x^x=0) do vậy nên 2 số giống nhau sẽ triệu tiêu nhau
	   return ans;
    }
};
int main(){
    Solution solution;
    vector<int> nums = {2, 2, 3, 3, 4, 5, 5};
    cout << solution.singleNumber(nums);
    return 0;
}