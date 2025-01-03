#include <iostream>
#include <string>

using namespace std;

bool laQuanHe(const string &qhe) {
    return qhe == "<" || qhe == ">" || qhe == "=" || qhe == "<=" || qhe == ">=" || qhe == "<>";
}

int main()
{
    string relation;
    cout << "Nhap quan he kt: ";
    cin >> relation;

    if (laQuanHe(relation))
    {
        cout << "'" << relation << "' la quan he hop le\n";
    } else {
        cout << "'" << relation << "' khong phai la quan he hop le.\n";
    }
    return 0;
}
