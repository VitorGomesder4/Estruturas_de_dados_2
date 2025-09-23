#include <cstdlib>

unsigned long long termial(int termial){ //Função para calcular o termial de n

    unsigned long long int total = 0; //valor neutro para soma

    for (int i = termial; i > 0; i--) {
        total += i;
    }
    
    return total;
}

unsigned long long fatorial(int fatorial){ //Função para calcular o fatorial de n
    
    unsigned long long total = 1; //valor neutro para multiplicação

    for (int i = fatorial; i > 0; i--) {
        total = total * i;
    }
    return total;
}

long long exponencial(int base, int expoente){ //Função para calcular o fatorial de n
    
    unsigned long long total = 1; //valor neutro para multiplicação
    
    for (int i = expoente; i > 0; i--) {
        total = total * base;
    }
    return total;
}

float exponencial_negativo(int base, int expoente){
    float total = 1;

    for (int i = abs(expoente); i > 0; i--) {
        total *= base;
    }

    total = 1/total;
    return total;
}