#ifndef PROGA_SQUARE_H
#define PROGA_SQUARE_H

#include <math.h>

struct square{
    float x1, y1;
    float x2, y2;
};

float squarePerimeter(struct square square);
float squareArea(struct square square);


#endif
//Директива #endif используется для обозначения конца блока #if. 
//Данная программа выводит сообщение на экран, поскольку, как 
//определено в программе, МАХ имеет значение больше 99.