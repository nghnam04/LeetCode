#include<iostream>
#include<string>
using namespace std;
/*
Hàm tìm kiếm một từ trong chuỗi và trả về chỉ số đầu tiên của từ đó
Nếu không tìm thấy trả về -1
*/
    int strStr(string haystack, string needle) {
        int position = haystack.find(needle);
        if(position == string::npos) return -1;
        return position;
    }
    int main(){
        string a, b;
        cin >> a;
        fflush(stdin);
        cin >> b;
         cout << strStr(a, b);
    }


