#include <stdio.h>

unsigned long long int termial(int termial){ //Função para calcular o termial de n

    unsigned long long int total = 0; //valor neutro para soma

    for (int i = termial; i > 0; i--) {
        total += i;
    }
    
    return total;
}

unsigned long long int fatorial(int fatorial){ //Função para calcular o fatorial de n
    
    unsigned long long total = 1; //valor neutro para multiplicação

    for (int i = fatorial; i > 0; i--) {
        total = total * i;
    }
    return total;
}

int main(){
    unsigned int parametro_termial = 0, parametro_fatorial = 0; //parametros

    unsigned long long termial_resultado = 0, fatorial_resultado = 0; //resultados

    unsigned short int choice; //escolha no menu

    bool running = true; //processo do programa

    do {
        //Esperando usuario escolher oque fazer
        printf("\n\n(1): Calcular termial");
        printf("\n(2): Calcular fatorial");
        printf("\n(3): Sair\n");
        scanf("%hu", &choice);

        switch (choice) {


            case 1: //No caso 1 é calculado o n? e depois exibido o resultado

                do {
                    printf("\n\nDigite um numero inteiro positivo a ser calculado o termial: ");
                    scanf("%d", &parametro_termial);
                    
                    if (parametro_termial > 0) { //Se o numero for valido para a operação a gente quebra o loop
                        break;
                    }else { //Se não a exibe um mensagem dizendo que o valor é invalido e continua a pedir
                        printf("\nERRO");
                        printf("\n\nDigite um valor inteiro positivo maior que 0\n\n");
                    }
                }while (true);


                termial_resultado = termial(parametro_termial); //processando o fatorial do numero e em seguida exibindo
                printf("\n\n%d? = %lld", parametro_termial, termial_resultado);

                break;
            

            case 2://No caso 2 é calculado o n! e depois exibido o resultado
                
                do {
                    printf("\n\nDigite um numero inteiro positivo a ser calculado o fatorial (maximo que consegue exibir é 20): ");
                    scanf("%d", &parametro_fatorial);

                    if (parametro_fatorial > 0) { //Se o numero for valido para a operação a gente quebra o loop
                        break;
                    }else { //Se não a exibe um mensagem dizendo que o valor é invalido e continua a pedir
                        printf("\nERRO");
                        printf("\nDigite um valor inteiro positivo maior que 0\n\n");
                    }
                }while (true);

                fatorial_resultado = fatorial(parametro_fatorial); //processando o fatorial do numero e em seguida exibindo
                printf("\n\n%d? = %lld", parametro_fatorial, fatorial_resultado);

                break;


            case 3: //Nesse caso a execução é terminada
                printf("\nTerminando execução..\n");
                running = false;
                break;
        }
    }while (running != false);

    return 0;
}