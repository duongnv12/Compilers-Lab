#include <iostream>
#include <string>

using namespace std;

bool laChuSo(char c) {
    return c >= '0' && c <= '9';
}

bool laDau(char c) {
    return c == '+' || c == '-';
}

bool laSo(const string &so) {
    if (so.empty()) {
        return false;
    }

    bool coDau = laDau(so[0]);
    size_t start = coDau ? 1 : 0;
    bool coCham = false;

    for (size_t i = start; i < so.size(); ++i) {
        char c = so[i];
        if (c == '.') {
            if (coCham) return false;
            coCham = true;
        } else if (!laChuSo(c)) {
            return false;
        }
    }

    return true;
}

int main()
{
    string number;
    cout << "Nhap so kt: ";
    cin >> number;

    if (laSo(number))
    {
        cout << "'" << number << "' la so hop le\n";
    } else {
        cout << "'" << number << "' khong phai la so hop le.\n";
    }
    return 0;
}
