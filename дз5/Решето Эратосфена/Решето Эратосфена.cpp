#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int numcheck() {
    string a;
    for (int k = 0; k < 1; k++) {
        cin >> a;
        bool d = true;
        for (int i = 0; i < size(a); i++) {
            if (!(isdigit((unsigned char)a[i]) || a[0] == '-')) {
                cout << "Введите числовое значение : ";
                k--;
                cin.clear();
                d = false;
                break;
            }
        }
        if (d) {
            if (stoi(a) < 2) {
                k--;
                cout << "Введите числовое значение большее 2: ";
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
        int n;
        cout << "Введите число : ";
        n = numcheck();
        unsigned int start_time = clock();
        
        string nums = "2\n";
        for (int i = 3; i < n + 1; i += 2) {
            bool a = true;
            for (int j = 3; j < i - 1; j += 2) {
                if (j < i) {
                    if (i % j == 0) {
                        a = false;
                        break;
                    }
                }
            }
            if (a) {
                nums += to_string(i) + '\n';
                //cout << endl << i;
            }
        }
        cout << nums;

        unsigned int end_time = clock();
        cout << "\n\nВремя: " << end_time - start_time << endl;
        system("pause");
    }
}
/*
int main()
{
    setlocale(LC_ALL, "RUS");
    while (true) {
        system("cls");
        int n;
        cout << "Введите число : ";
        n = numcheck();
        unsigned int start_time = clock();
        
        cout << 2;
        for (int i = 3; i < n + 1; i += 2) {
            bool a = true;
            for (int j = 3; j < i - 1; j += 2) {
                if (j < i) {
                    if (i % j == 0) {
                        a = false;
                        break;
                    }
                }
            }
            if (a) {
                
                cout << endl << i;
            }
        }


        unsigned int end_time = clock();
        cout << "\n\nВремя: " << end_time - start_time << endl;
        system("pause");
    }
}*/