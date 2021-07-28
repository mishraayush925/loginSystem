#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    ofstream fileD;

    cout << "which file do you want to open?";
    cin >> filename;

    fileD.open("new_filessss");
    fileD << "lalala";
    fileD.close();

    return 0;
}