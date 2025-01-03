// #include <iostream>
// using namespace std;

// bool isIdentifier(const string& s) {
//     if (!isalpha(s[0])) return false; // Kiểm tra ký tự đầu tiên có phải chữ cái không
//     for (char c : s) {
//         if (!isalnum(c)) return false; // Kiểm tra từng ký tự có phải chữ cái hoặc chữ số không
//     }
//     return true;
// }

// int main() {
//     string test;
//     cout << "Nhập vào một chuỗi: ";
//     cin >> test;
//     if (isIdentifier(test)) {
//         cout << test << " là một tên hợp lệ trong Pascal.\n";
//     } else {
//         cout << test << " không phải là một tên hợp lệ trong Pascal.\n";
//     }
//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;
bool laKyTu(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool laChuSo(char c) {
    return c >= '0' && c <= '9';
}

bool ktTen(const string &ten) {
    if (ten.empty()) {
        return false;
    }

    if (!laKyTu(ten[0])) {
        return false;
    }

    for (size_t i = 1; i < ten.size(); ++i) {
        char c = ten[i];
        if (!laKyTu(c) && !laChuSo(c) && c != '_') {
            return false;
        }
    }
    return true;
}

int main()
{
    string name;
    cout << "Nhap ten kt: ";
    cin >> name;

    if (ktTen(name))
    {
        cout << "'" << name << "' ten hop le\n";
    } else {
        cout << "'" << name << "' ten khong hop le.\n";
    }
    return 0;
}