#include <conio.h>
#include <iostream>
using namespace std;
#define KEY_ESC 27
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//Define 1234567890 keys
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

void recursiveFunction() {
    char key = _getch();
    if (key == KEY_ESC) {
        cout << "ESC key pressed" << endl;
    } else {
        cout << "Key pressed: " << key << endl;
        recursiveFunction();
    }
    
};

int main() {
    recursiveFunction();
    return 0;
}
