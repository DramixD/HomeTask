#include <iostream>
#include <time.h>

using namespace std;

class dot {
    int x;
    int y;
public:
    dot() {
        x = rand() % 40 - 20;
        y = rand() % 40 - 20;
    }
    dot(int a, int b) {
        x = a;
        y = b;
    }

    void show() {
        cout << "x = " << x << "\ny = " << y << endl;
    }

    void change() {
        cout << "enter new x coordinate: "; cin >> x;
        cout << "enter new y coordinate: "; cin >> y;
    }

    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }
};

void show_dots(dot arr[], int size) {
    char field[40][40];
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            if (i == 20) {
                if (j == 20)
                    field[i][j] = '+';
                field[i][j] = '-';
            }
            else if (j == 20) {
                field[i][j] = '|';
            }
            else
                field[i][j] = ' ';
        }
    }
    for (int i = 0; i < size; i++) {
        field[arr[i].get_x()+20][arr[i].get_y()+20] = 'o';
    }

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
}




int main()
{   
    srand(time(NULL));

    dot first;
    first.show();
    first.change();
    first.show();

    int a, b;
    cout << "enter coordinate for new dot.\nx: "; cin >> a;
    cout << "y: "; cin >> b;
    dot second(a, b);
    second.show();


    cout << "new 10 dots:\n";

    dot arr[10];
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
        arr[i].show();
    }
    cout << endl;
    show_dots(arr, 10);

}


