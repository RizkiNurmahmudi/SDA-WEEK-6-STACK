#ifndef STACK_H
#define STACK_H

#include "linked.h"  // Mengimpor definisi linked list

// Definisi struktur Stack menggunakan linked list
typedef struct {
    address top;  // Pointer ke elemen teratas stack
} Stack;

// Deklarasi fungsi-fungsi stack
void initializeStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, infotype value);
infotype pop(Stack *s);
void freeStack(Stack *s);  // Fungsi untuk membebaskan memori stack

// Deklarasi fungsi konversi desimal ke biner
void decimalToBinary(int decimal);

#endif
