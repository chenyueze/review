/*************************************************************************
	> File Name: 121-石头剪刀布.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 三  9/ 2 18:35:48 2020
 ************************************************************************/
#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "TIE" << endl;
    } else if (a == 'O' && b == 'Y' ||
               a == 'Y' && b == 'H' ||
               a == 'H' && b == 'O') {
        cout << "MING" << endl;           
    } else {
        cout << "LI" << endl;
    }
    return 0;
}
