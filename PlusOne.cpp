#include<iostream>
#include<vector>
using namespace std;
//Hàm tăng mảng chứa các chữ số của một số long long int lên 1

    vector<int> plusOne(vector<int>& digits) {
         for (int i = digits.size() - 1; i >= 0; i--) { //Duyệt từ cuối mảng về
            int num = digits[i] + 1;
            if (num == 10 && i != 0) { //Nếu các số không phải ở đầu cộng thêm 1 bằng 10
                digits[i] = 0; //
            }
            else {
                digits[i] = num; //Nếu là các số 0-9 thì cộng thêm 1 rồi break vòng lặp
                break;
            }
        }
        if (digits[0] == 10) { //Nếu phần tử đầu tiên là 10 thì thay bằng 1 và thêm số 0 vào cuối
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }

    
    int main(){
        vector<int> digits;
        int n, input;
        cin >> n; //Nhập vào số lượng phần tử của vector
        for(int i=0; i<n; i++){ //Nạp các chữ số đó vào vector
            cin >> input;
            digits.push_back(input);
        }
        cout << "Số nguyên sau khi tăng lên 1 là: ";
       plusOne(digits);
       for(auto i : digits){
        cout << i;
       }
    return 0;
    }
