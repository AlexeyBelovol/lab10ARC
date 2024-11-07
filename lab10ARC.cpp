#include <iostream>

void main() {
    long n = 5;  // Приклад значення n
    float A = 2.5, B = 5.3, C = -21, result;

    __asm {
        finit; очищення регістрів співпроцесора
        fld     n; завантаження n у вершину стека
        fmul    st(0), st(0); множення n* n(n ^ 2)
        fmul    A; множення на 2.5
        fld     n; завантаження n в вершину стека
        fmul    B; множення на 5.3
        fadd    st(1), st(0); додавання 2.5n ^ 2 + 5.3n
        fadd    C; додавання - 21
        fstp    result; збереження результату
    }

    std::cout << "Result: " << result << std::endl;  // Виведення результату
}
