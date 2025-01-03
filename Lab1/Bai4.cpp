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

bool laQuanHe(const string &qhe) {
    return qhe == "<" || qhe == ">" || qhe == "=" || qhe == "<=" || qhe == ">=" || qhe == "<>";
}

int main()
{
    string input;
    cout << "Nhap chuoi kiem tra: ";
    cin >> input;

    if (ktTen(input))
    {
        cout << "'" << input << "' la ten hop le\n";
    } else if (laSo(input)) {
        cout << "'" << input << "' la so hop le\n";
    } else if (laQuanHe(input)) {
        cout << "'" << input << "' la quan he hop le\n";
    } else {
        cout << "'" << input << "' khong hop le.\n";
    }
    return 0;
}
