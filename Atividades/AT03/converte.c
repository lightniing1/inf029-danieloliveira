#include "converte.h"

float ConverteEmF (float x){
    x = (x * 1.8) + 32;
    return x;
}

float ConverteEmC (float x){
    x = (x - 32) / 1.8;
    return x;
}