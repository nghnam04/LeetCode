#include<iostream>
#include<vector>
using namespace std;
//Hàm tăng mảng chứa các chữ số của một số long long int lên 1

    vector<int> plusOne(vector<int>& digits) {
         for (int i = digits.size() - 1; i >= 0; i--) {
            int num = digits[i] + 1;
            if (num == 10 && i != 0) {
                digits[i] = 0;
            }
            else {
                digits[i] = num;
                break;
            }
        }
        if (digits[0] == 10) {
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
