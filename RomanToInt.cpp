#include<iostream>
#include <string>
#include<map>
using namespace std;

//Hàm chuyển số la mã thành số nguyên
    int romanToInt(string s) {
        map<char, int> roman = { //Bảng tra các giá trị la mã
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
        int total=0;
        /*
        Hàm duyệt từ đầu tới cuối chuỗi la mã
        Nếu phần tử trước lớn hơn phần tử sau thì cộng nó vào total và nhỏ hơn thì trừ đi
        */
         for(auto i=0; i<=s.length()-1; i++){
            if(roman[s[i]] < roman[s[i+1]]) total -= roman[s[i]];
            else total += roman[s[i]];
        }
        return total;
    }
    
    int main(){
        string roman;
        cin >> roman;
        cout << romanToInt(roman);
    return 0;
    }
