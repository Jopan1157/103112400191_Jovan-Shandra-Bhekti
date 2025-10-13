#include <iostream>
using namespace std;


void tampilArray(int data[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}


void tukarElemen(int a[3][3], int b[3][3], int i, int j) {
    int temp = a[i][j];
    a[i][j] = b[i][j];
    b[i][j] = temp;
}


void tukarPtr(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{4,2,3},{6,3,2},{8,5,9}};
    int B[3][3] = {{9,4,6},{3,1,2},{7,4,4}};
    int x = 10, y = 20;

    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    
    tukarElemen(A, B, 1, 1);

    cout << "\nSetelah tukar elemen (1,1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "Array B:\n";
    tampilArray(B);

    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPtr(&x, &y);
    cout << "Sesudah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}
