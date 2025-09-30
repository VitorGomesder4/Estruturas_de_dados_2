#include <cstdlib>
/*
unsigned long long int termial(int termial){ //Função para calcular o termial de n

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
*/

unsigned long long int termial(int numero){ //Função para calcular o termial de n

    if (numero <= 0) { //condição de parada da função recursiva
        return 0;
    }
    
    return numero + termial(numero - 1);
}

unsigned long long fatorial(int numero){ //Função para calcular o fatorial de n

    if (numero <= 1) { //condição de parada da função recursiva
        return 1;
    }
    return numero * fatorial(numero - 1);
}

long long exponencial(int base, int expoente){ //Função para calcular o exponencial de n
    
    if (expoente == 0) { //retorna 1 direto caso o expoente for 0
        return 1;
    }

    if (expoente == 1) { //condição de parada da função recursiva
        return base;
    }

    return base * exponencial(base, expoente - 1);
}

float exponencial_negativo(int base, int expoente){ //função para calcular a base elevada a expoentes negativos inteiros

    int abs_expoente = abs(expoente); //pegando o valor absoluto para a função exponencial

    float resultado = exponencial(base, abs_expoente);

    if (expoente < 0) {
        return 1/resultado;
    }else { //provavelmente nunca vai ser executado se tiver sido tratado no main
        return resultado;
    }
}