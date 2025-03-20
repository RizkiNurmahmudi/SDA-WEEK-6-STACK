#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk inisialisasi stack
void initializeStack(Stack *s) {
    s->top = NULL;  // Stack kosong, top = NULL
}

// Fungsi untuk mengecek apakah stack kosong
int isEmptyStack(Stack *s) {
    return isEmpty(s->top);  // Menggunakan fungsi isEmpty dari linked.h
}

// Fungsi untuk menambahkan elemen ke stack (push)
void push(Stack *s, infotype value) {
    address newNode;
    Create_Node(&newNode);  // Buat node baru menggunakan fungsi dari linked.c
    if (newNode != NULL) {
        Isi_Node(&newNode, value);  // Isi node dengan nilai
        Ins_Awal(&(s->top), newNode);  // Sisipkan node di awal (top stack)
    } else {
        printf("Gagal mengalokasikan memori untuk node baru.\n");
    }
}

// Fungsi untuk menghapus elemen dari stack (pop)
infotype pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack kosong, tidak dapat menghapus elemen.\n");
        return -1;  // Nilai default jika stack kosong
    } else {
        infotype value;
        Del_Awal(&(s->top), &value);  // Hapus node teratas dan ambil nilainya
        return value;
    }
}

// Fungsi untuk membebaskan memori stack
void freeStack(Stack *s) {
    HapusSemua(&(s->top));  // Gunakan fungsi HapusSemua dari linked.c
}

// Fungsi untuk mengonversi bilangan desimal ke biner
void decimalToBinary(int decimal) {
    Stack s;
    initializeStack(&s);

    printf("\nProses Konversi:\n");
    printf("----------------\n");

    // Proses konversi desimal ke biner
    while (decimal > 0) {
        int remainder = decimal % 2;  // Hitung sisa bagi
        printf("%d / 2 = %d, Sisa = %d\n", decimal, decimal / 2, remainder);
        push(&s, remainder);  // Simpan sisa bagi ke stack
        decimal /= 2;  // Bagi bilangan desimal dengan 2
    }

    // Tampilkan linked list yang digunakan dalam stack
    printf("\nLinked List dalam Stack\n");
    printf("----------------------------------------\n");
    Tampil_List(s.top);  // Gunakan fungsi Tampil_List dari linked.c

    // Cetak hasil biner dari stack
    printf("\nHasil Konversi:\n");
    printf("----------------\n");
    printf("Bilangan biner: ");
    while (!isEmptyStack(&s)) {
        printf("%d", pop(&s));  // Keluarkan elemen dari stack
    }
    printf("\n");

    // Bebaskan memori stack
    freeStack(&s);
}
