#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//Hàm cộng 2 số nhị phân
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0; //Carry là biến nhớ
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';    //Chuyển thành số nguyên nên từ chuỗi phải bỏ đi ký tự null
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0; //Biến nhớ chỉ có thể là 1 hoặc 0
            res += to_string(sum % 2); //Cộng thêm vào chỉ là 0 hoặc 1
        }
        if(carry) res += to_string(carry); //Nếu vẫn còn biến nhớ thì nối tiếp vào sau chuỗi
        reverse(res.begin(), res.end()); //Đảo lại chuỗi do khi cộng theo thứ tự trên kết quả được viết theo chiều ngược lại
        return res;
    }
};

int main(){
     Solution solution;
    string a = "1010";
    string b = "1011";
    string result = solution.addBinary(a, b);
    cout << "Result of adding " << a << " and " << b << " is " << result << std::endl;
    return 0;
}