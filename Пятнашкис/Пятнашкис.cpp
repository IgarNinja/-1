#include <iostream>
#include <Windows.h>

using namespace std;
char term;
char difficulty;
int board3x3[3][3];
int board4x4[4][4];
void FillingBoard3x3(int(*arr)[3]);
void WrongStep3x3(int(*arr)[3]);
void FillingBoard4x4(int(*arr)[4]);
void DrawingBoard_3x3(int(*arr)[3]);
void DrawingBoard_4x4(int(*arr)[4]);
void PlayerStep4x4(int(*arr)[4],  char step);
void WrongStep4x4(int(*arr)[4]);
void WinCheck4x4(int(*arr)[4]);
void PlayerStep3x3(int(*arr)[3],  char step);
void WinCheck3x3(int(*arr)[3]);

int main()
{
    FillingBoard3x3(board3x3);
    FillingBoard4x4(board4x4);
    char step;
    cout << "Choose the difficulty (e(easy)/h(hard)):\n";
    cin >> term;
    while (term == 'e') {
        system("cls");
        DrawingBoard_3x3(board3x3);
        cout << "Enter route (w - up/ s - down/ d - right/ a - left) - "; cin >> step;
        PlayerStep3x3(board3x3, step);
        DrawingBoard_3x3(board3x3);
        WinCheck3x3(board3x3);
    }
    while (term == 'h') {
        system("cls");
        DrawingBoard_4x4(board4x4);
        cout << "Enter route (w - up/ s - down/ d - right/ a - left) - "; cin >> step;
        PlayerStep4x4(board4x4,  step);
        DrawingBoard_4x4(board4x4);
        WinCheck4x4(board4x4);
    }
}
void WinCheck4x4(int(*arr)[4]) {
    int WinCheckArr[4][4] = { {1,2,3,4 }, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0} };
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == WinCheckArr[i][j]) count++;
        }
    }
    if (count == 16) {
        cout << "You WIN!\n";
        term = 'n';
    }
}
void PlayerStep3x3(int(* arr)[3], char step) {
    int t1, t2;
    int temp;
    // Определяем местоположение нуля
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 0) {
                t1 = i;
                t2 = j;
            }
        }
    }

    if (step == 'w') {
        if (t1 == 0) WrongStep3x3(arr);
        else {
            temp = arr[t1 - 1][t2];
            arr[t1 - 1][t2] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 's') {
        if (t1 == 2) WrongStep3x3(arr);
        else {
            temp = arr[t1 + 1][t2];
            arr[t1 + 1][t2] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 'd') {
        if (t2 == 2) WrongStep3x3(arr);
        else {
            temp = arr[t1][t2 + 1];
            arr[t1][t2 + 1] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 'a') {
        if (t2 == 0) WrongStep3x3(arr);
        else {
            temp = arr[t1][t2 - 1];
            arr[t1][t2 - 1] = 0;
            arr[t1][t2] = temp;
        }
    }
    else {
        WrongStep3x3(arr);
    }
}
void WrongStep3x3(int(*arr)[3]) {
    char step;
    cout << "Wrong, try one more time:\n ";
    cout << "Enter route (w - up/ s - down/ d - right/ a - left) - "; cin >> step;
    PlayerStep3x3(arr, step);
}
void WinCheck3x3(int(*arr)[3]) {
    int WinCheckArr[3][3] = { {1,2,3}, {4,5,6},{7,8,0} };
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == WinCheckArr[i][j]) count++;
        }
    }
    if (count == 9) {
        cout << "You WIN!\n";
        term = 'n';
    }
}
void FillingBoard3x3(int(*arr)[3]) {
    srand(time(NULL));
    // Список для контроля повторений
    int board_numbers[9] = {0,0,0,0,0,0,0,0};
    int RandNumb;
    int count = 0;
    // Происходит заполнение поля 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            RandNumb = rand() % 9;
            while (board_numbers[RandNumb] == 1) {
                RandNumb = rand() % 9;
            }
            board_numbers[RandNumb] = 1;
            arr[i][j] = RandNumb;
        }
    }
}
void DrawingBoard_3x3(int(*arr)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|" << arr[i][j] << "|";
        }
        cout << endl;
    }
}
void FillingBoard4x4(int(*arr)[4]) {
    srand(time(NULL));
    // Список для контроля повторений
    int board_numbers[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int RandNumb;
    int count = 0;
    // Происходит заполнение поля 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            RandNumb = rand() % 16;
            while (board_numbers[RandNumb] == 1) {
                RandNumb = rand() % 16;
            }
            board_numbers[RandNumb] = 1;
            arr[i][j] = RandNumb;
        }
    }
}
void DrawingBoard_4x4(int(*arr)[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "|" << arr[i][j] << "|";
        }
        cout << endl;
    }
}
void WrongStep4x4(int(*arr)[4]) {
    char step;
    cout << "Wrong, try one more time:\n ";
    cout << "Enter route (u - up/ d - down/ r - right/ l - left) - "; cin >> step;
    PlayerStep4x4(arr, step);
}
void PlayerStep4x4(int(*arr)[4], char step) {
    int t1, t2;
    int temp;
    // Определяем местоположение нуля
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 0) {
                t1 = i;
                t2 = j;
            }
        }
    }

    if (step == 'w') {
        if (t1 == 0) WrongStep4x4(arr);
        else {
            temp = arr[t1 - 1][t2];
            arr[t1 - 1][t2] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 's') {
        if (t1 == 3) WrongStep4x4(arr);
        else {
            temp = arr[t1 + 1][t2];
            arr[t1 + 1][t2] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 'd') {
        if (t2 == 3) WrongStep4x4(arr);
        else {
            temp = arr[t1][t2 + 1];
            arr[t1][t2 + 1] = 0;
            arr[t1][t2] = temp;
        }
    }
    else if (step == 'a') {
        if (t2 == 0) WrongStep4x4(arr);
        else {
            temp = arr[t1][t2 - 1];
            arr[t1][t2 - 1] = 0;
            arr[t1][t2] = temp;
        }
    }
    else {
        WrongStep4x4(arr);
    }
}