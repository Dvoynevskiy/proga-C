#include "square.h" //включать

float squarePerimeter(struct square square){
    float AB = sqrt(pow(square.x2 - square.x1, 2) + pow(square.y2-square.y1, 2));
    return 4*AB;
}
// Функция sqrt() возвращает квадратный корень аргумента num. При вызове функции 
//с отрицательным аргументом возникает ошибка области определения.

//Вычисляет x в степени y. Функция pow вычисляет x^y. При успешном завершении, pow возвращает вычисленное значение, x^y
float squareArea(struct square square){
    float AB = sqrt(pow(square.x2 - square.x1, 2) + pow(square.y2-square.y1, 2));
    return pow(AB, 2);
}
