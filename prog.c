#include <stdio.h>

// solicite a quantidade de notas a serem informadas em uma turma, 
// solicitando os dados dos alunos e ao final apresentando a média aritmética, a maior e a menor das notas informadas

struct pessoa{
    char nome[100];
    float n1, n2, n3, media, maior_n, menor_n;
};

int main(){
    int quantidade_notas = 0;
    struct pessoa p[100] = {0};

    printf("Quantidade de notas a serem informadas: \n\n");
    scanf("%d", &quantidade_notas);

    for (int i = 0; i < quantidade_notas; i++) {

        printf("Digite o nome do %d aluno: \n", i+1);
        scanf("%s", p[i].nome);
    
        printf("Digite a 1 nota: \n");
        scanf("%f", &p[i].n1);
    
        printf("Digite a 2 nota: \n");
        scanf("%f", &p[i].n2);
    
        printf("Digite a 3 nota: \n");
        scanf("%f", &p[i].n3);

        p[i].maior_n = p[i].n1;
        p[i].menor_n = p[i].n1;

        if (p[i].maior_n < p[i].n2) {
            p[i].maior_n = p[i].n2;
        }
        
        if (p[i].maior_n < p[i].n3) {
            p[i].maior_n = p[i].n3;
        }

        if (p[i].menor_n > p[i].n2) {
            p[i].menor_n = p[i].n2;
        }
        
        if (p[i].menor_n > p[i].n3) {
            p[i].menor_n = p[i].n3;
        }

        p[i].media = (p[i].n1 + p[i].n2 + p[i].n3) / 3.0f;

        printf("A respeito de %s, sua média é %.2f, a maior nota é %.2f e a menor nota é %.2f\n\n", p[i].nome, p[i].media, p[i].maior_n, p[i].menor_n);
    }
}