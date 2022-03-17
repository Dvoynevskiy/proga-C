#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    char *filename;
    bool even = false;
    char ch;

    filename = argv[1];
    FILE *file = fopen(filename, "r");

    while (ch != EOF) {
        ch = getc(file);// Макрос getc() возвращает следующий за текущей 
        //позицией символ во входном потоке stream и дает приращение указателю
        // положения в файле. Символ считывается как unsigned char, преобра­зованный к переменной целого типа.c
        if (ch == '\n')
            even = !even;
        if (even)
            printf("%c", ch);
    }
    printf("\n");
    fclose(file);
    return 0;
}