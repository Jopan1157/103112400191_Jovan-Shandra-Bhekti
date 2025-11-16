#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -999;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack t1, t2;
    CreateStack(t1);
    CreateStack(t2);

    while (!isEmpty(S)) push(t1, pop(S));
    while (!isEmpty(t1)) push(t2, pop(t1));
    while (!isEmpty(t2)) push(S, pop(t2));
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] < x) {  
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
void getInputStream(Stack &S) {
    char c;

    // baca karakter satu per satu sampai user tekan ENTER (newline)
    while (cin.get(c) && c != '\n') {
        if (isdigit(c)) {
            int x = c - '0';   // ubah char ke int
            push(S, x);        // langsung push biasa
        }
    }
}



