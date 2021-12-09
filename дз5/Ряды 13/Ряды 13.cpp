#include <iostream>
#include <string>
using namespace std;

int numcheck() {
    string a;
    for (int k = 0; k < 1; k++) {
        cin >> a;
        bool d = true;
        for (int i = 0; i < size(a); i++) {
            if (!(isdigit((unsigned char)a[i]) || a[0] == '-')) {
                cout << "Введите натуральное число m < 27: ";
                k--;
                cin.clear();
                d = false;
                break;
            }
        }
        if (d == true) {
            if (stoi(a) <= 0 || stoi(a) > 27) {
                k--;
                cout << "Введите натуральное число m < 27: ";
                cin.clear();
            }
        }
    }
    return stoi(a);
}

int main()
{
    setlocale(LC_ALL, "RUS");

    while (true) {
        system("cls");
        int m;
        cout << "Задание \"Ряды\" №13\n\nДано натуральное число m < 27. Получить все трехзначные целые числа, сумма цифр которых равна m\n\nВведите натуральное число m < 27: ";
        m = numcheck();
        string nums;
        int count = 0;
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (i + j + k == m) {
                        count++;
                    }
                }
            }
        }
        int* numbers = new int[count];
        count = 0;
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (i + j + k == m) {
                        numbers[count] = i * 100 + j * 10 + k;
                        count++;
                    }
                }
            }
        }

        for (int i = 0; i < count; i++) {
            cout << numbers[i] << endl;
        }
        system("pause");
    }
    return 0;
}
