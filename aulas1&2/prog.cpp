// Escreva um algoritmo que solicita ao usuario o nome e tres notas de N alunos en una turma e ao final, 
// 2 // apresente ao usuario:
// Versao 01: A quantidade de alunos na turma OK e a media aritmetica das notas de cada aluno
// Versao 82: Solicitar ao usuario a media de aprovacao e a quantidade de provas e gerar Relati3rio com nome e 5 // Versao 03: Introduzir o campo sexo (M-masculino ou F-feminino) e gerar estatistiaca de aprovaÃ§Ã£o/reproval
// Versao 84: Apresentar os relatorios ordenados por media aritmetica das notas
// Versao 05: Apresaentar um menu de opcoes
// 1: Relatorio de aprovados
// 2: Relatorio de reprovados
// 3: Sair do programa

//&& se a primeira condição for true ele ja quebra e nem checa as outras (curto circuito)

//& mesmo se a primeira condição for true para quebra ele continua a checar o proximo (sem curto circuito)


#include <stdio.h>

#define max_alunos 100
#define max_notas 10

char char_sn = '\0';
float media_apr = 0, somatorio = 0;
int quantos_alunos = 0, quantas_notas_a = 0, len_notas = 1, contador = 0;

struct alunos{
    char nome[40];
    char sexo;
    float arr_notas[max_notas];
    float media;
    bool aprovado;
};

alunos aluno[max_alunos] = {};

//========================================================================================//  
int main(){

    //Estabelecendo os valores para os iteradores e media de aprovação

    do {
        printf("Quantos alunos a turma possui? ");
        scanf("%d", &quantos_alunos);
    }while (quantos_alunos<1 || quantos_alunos>100);

    do {
        printf("Media aprovação: (5 a 8) ");
        scanf("%f", &media_apr);
    }while (media_apr<5 || media_apr>8);
    
    do {
        printf("Notas por aluno 3 a 10: ");
        scanf("%d", &quantas_notas_a);
    }while (quantas_notas_a<3 || quantas_notas_a>10);

//========================================================================================//    

    //Pecorrendo os arrays aluno e notas

    for (int i=0; i<quantos_alunos; i++) { //Para cada aluno "i", faça o abaixo:

        printf("Nome do aluno {%d}", i+1);
        scanf("%s", aluno[i].nome);

        do {
            printf("Sexo (M/N)");
            scanf(" %c", &aluno[i].sexo);
        }while (aluno[i].sexo != 'M' && aluno[i].sexo != 'm' && aluno[i].sexo != 'F' && aluno[i].sexo != 'f');


        for (int j=0; j<quantas_notas_a; j++) { //Para cada nota "j" do aluno "i" do:
            printf("Digite a %d nota", j+1);
            scanf("%f", &aluno[i].arr_notas[j]);
            contador+=1;
        }


        for (int n=0; n<contador; n++) { //Somando todas notas para calculo da media
            somatorio += aluno[i].arr_notas[n];
        }

        aluno[i].media = somatorio/contador; // Media = (soma das notas) / (numero de notas do aluno)

        //SE nota > media de aprovação, aprovado sera verdadeiro, Else: aprovado sera falso
        if (aluno[i].media >= media_apr) {
            aluno[i].aprovado = true;
        }else {
            aluno[i].aprovado = false;
        }

        //Resetando somatorio e contador para proximo aluno
        somatorio = 0;
        contador = 0;


        //Perguntando se o usuario se deseja continuar, tambem a razao da variavel 'contador':
        do {
            printf("Continuar com o proximo aluno ou parar por aqui? (Y/N)");
            scanf("%c", &char_sn);
        }while (char_sn != 'Y' && char_sn != 'y' && char_sn != 'N' && char_sn != 'n');
    }

//========================================================================================//  
    return 0;
}

//Oque falta fazer: Gerar relatorios, Apresentar um menu de opções, Relatorio com aprovados, Relatorio com reprovados

//Opcional se tiver tempo: gerar Estatísticas