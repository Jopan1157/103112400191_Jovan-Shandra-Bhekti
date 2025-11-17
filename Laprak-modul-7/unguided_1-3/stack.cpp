#include "stack.h"
using namespace std;

void CreateStack(Stack &S){
    S.top = Nil;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.info[S.top] = x;
    }else{
        cout << "Stack penuh" << endl;
    }

}
infotype pop(Stack &S) {
    infotype x = -999;  
    if (!isEmpty(S)) {  
        x = S.info[S.top];  
        S.top--;  
    } else {
        cout << "Stack Kosong!" << endl;  
    }
    return x; 
}
void printInfo(Stack S) {
    if (isEmpty(S)) {  
        cout << "Stack Kosong" << endl;  
    } else {
        cout << "[TOP] ";  
        for (int i = S.top; i >= 0; i--) {  
            cout << S.info[i] << " ";  
        }
        cout << endl; 
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  
        Stack temp1, temp2;  
        CreateStack(temp1); CreateStack(temp2);  
        while (!isEmpty(S)) { push(temp1, pop(S)); }  

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  
    }
}
bool isEmpty(Stack S){
    return S.top == Nil;
}
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  
}
void pushAscending(Stack &S, int x){
    Stack Temp1, Temp2;
    CreateStack(Temp1);
    CreateStack(Temp2);
    int t;
    while(!isEmpty(S)){
        t = pop(S);
        if (t < x){
            push(Temp1, t);
            //break;
        }else{
            push(Temp2, t);
        }
    }
    while(!isEmpty(Temp1)){
        push(S, pop(Temp1));
    }
    push(S, x);
    while(!isEmpty(Temp2)){
       
        push(S, pop(Temp2));
    }
}
void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);           

    while (c != '\n') {  
        push(S, c - '0'); 
        cin.get(c);       
    }
}
