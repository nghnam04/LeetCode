 #include<iostream>
 #include<vector>
 #include<map>
 using namespace std;
//Hàm tìm và in ra chỉ số của 2 phần tử trong mảng có tổng bằng target truyền vào
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int, int> m;
        for(int i = 0; i < nums.size(); i++) { //Dùng map duyệt các phần tử vector, nếu phần tử có giá trị bằng target - phần tử có chỉ số i thì in 
            if(m.count(target - nums[i])) return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {0, 0};
    }
    int main(){
        int n;
        vector<int> vt={1, 2, 3, 4, 5, 6};
        cout << "Nhập vào target: ";
        cin >> n;
        vector<int> result = twoSum(vt, n);
        cout << "[" << result[0] << "," << result[1] << "]";
        return 0;
    }

    