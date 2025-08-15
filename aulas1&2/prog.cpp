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

float media_apr = 0, somatorio = 0;
int char_sn = 0, quantos_alunos = 0, quantas_notas_a = 0, len_notas = 1, contador = 0, total_alunos = 0, total_alunos_a = 0, total_alunos_r = 0, c; 

float total_m = 0, total_f = 0, M_aprovados= 0, F_aprovados = 0, M_reprovados, F_reprovados; 

struct alunos{
    char nome[40];
    char sexo;
    float arr_notas[max_notas];
    float media;
    bool aprovado;
};

alunos aluno[max_alunos] = {};
alunos alunos_aprovados[max_alunos] = {};
alunos aluno_reprovados[max_alunos] = {};

//========================================================================================//  
void cadastro(){

    //Estabelecendo os valores para os iteradores e media de aprovação

    do {
        printf("\nQuantos alunos a turma possui? ");
        scanf("%d", &quantos_alunos);
    }while (quantos_alunos<1 || quantos_alunos>100);

    do {
        printf("\nMedia aprovação: (5 a 8) ");
        scanf("%f", &media_apr);
    }while (media_apr<5 || media_apr>8);
    
    do {
        printf("\nNotas por aluno 3 a 10: ");
        scanf("%d", &quantas_notas_a);
    }while (quantas_notas_a<3 || quantas_notas_a>10);

//========================================================================================//    

    //Pecorrendo os arrays aluno e notas

    for (int i=0; i<quantos_alunos; i++) { //Para cada aluno "i", faça o abaixo:

        printf("\nNome do aluno {%d}", i+1);
        scanf("%s", aluno[i].nome);

        do {
            printf("\nSexo (M/F)");
            scanf(" %c", &aluno[i].sexo);
        }while (aluno[i].sexo != 'M' && aluno[i].sexo != 'm' && aluno[i].sexo != 'F' && aluno[i].sexo != 'f');


        for (int j=0; j<quantas_notas_a; j++) { //Para cada nota "j" do aluno "i" do:
            printf("\nDigite a %d nota", j+1);
            scanf("%f", &aluno[i].arr_notas[j]);
            contador+=1;
        }


        for (int n=0; n<contador; n++) { //Somando todas notas para calculo da media
            somatorio += aluno[i].arr_notas[n];
        }

        aluno[i].media = somatorio/quantas_notas_a; // Media = (soma das notas) / (numero de notas do aluno)

        //SE nota > media de aprovação, aprovado sera verdadeiro, Else: aprovado sera falso
        if (aluno[i].media >= media_apr) {
            aluno[i].aprovado = true;
            alunos_aprovados[total_alunos_a] = aluno[i];
            total_alunos_a++;
            if (aluno[i].sexo == 'M' || aluno[i].sexo == 'm') {
                total_m++;
                M_aprovados++;
            }else {
                total_f++;
                F_aprovados++;
            }
        }else {
            aluno[i].aprovado = false;
            aluno_reprovados[total_alunos_r] = aluno[i];
            total_alunos_r++;
            if (aluno[i].sexo == 'M' || aluno[i].sexo == 'm') {
                total_m++;
                M_reprovados++;
            }else {
                total_f++;
                F_reprovados++;
            }
        }
        total_alunos += 1;

        //Resetando somatorio e contador para proximo aluno
        somatorio = 0;
        contador = 0;

        if (i+1 != quantos_alunos) {
            //Perguntando se o usuario se deseja continuar, tambem a razao da variavel 'contador':
            do {
                printf("\n\nVocê informou %d alunos e faltam %d", i+1, quantos_alunos-(i+1));
                printf("\nContinuar com o proximo aluno? ('1' para sim)");
                scanf("%d", &char_sn);
            }while (char_sn != 1 && char_sn != 2);

            if (char_sn==1) {
                continue;
            }else {
                total_alunos = i;
                break;
            }
        }
    }
//========================================================================================//
}


int main(){
    cadastro();

    float taxa_apr_m = 0, taxa_repr_m = 0, taxa_apr_f = 0, taxa_repr_f = 0, taxa_apr_alunos = 0, taxa_repr_alunos = 0;
    int tipo_turma;

    if (total_m>0 && total_f>0) {
        //strcpy(tipo_turma, "misto");
        tipo_turma = 1;

    }else if (total_m>0 && total_f==0) {
        //strcpy(tipo_turma, "masculino");
        tipo_turma = 2;

    }else if (total_m==0 && total_f>0) {
        //strcpy(tipo_turma, "feminino");
        tipo_turma = 3;

    }else {
        //(tipo_turma, "");
        tipo_turma = 0;
    }


    float total_alunos_float = total_alunos;
    
    bool ocorrencia = true;
    char decide = '\0', decide2 = '\0';

    while (ocorrencia) {
        printf("\n\n1.Relatorios 2.Estatísticas 3.Exit\n");
        scanf(" %c", &decide);

        switch(decide) {

            case '1':
                do {
                    printf("\n\n1.Aprovados 2.Reprovados 3.Todos 4.Voltar ao menu principal\n");
                    scanf(" %c", &decide2);
                }while (decide2 != '1' && decide2 != '2' && decide2 != '3' && decide2 != '4');

                switch (decide2) {

                            case '1':
                                printf("\nAprovados: ");
                                for (int i = 0; i<total_alunos_a; i++) {
                                    printf("\n%s", alunos_aprovados[i].nome);
                                }
                                break;
                    
                            case '2':
                                printf("\nReprovados: ");
                                for (int i = 0; i<total_alunos_r; i++) {
                                    printf("\n%s", aluno_reprovados[i].nome);
                                }
                                break;
                            
                            case '3':

                                printf("\nAprovados: ");
                                for (int i = 0; i<total_alunos_a; i++) {
                                    printf("\n%s", alunos_aprovados[i].nome);
                                }

                                printf("\nReprovados: ");
                                for (int i = 0; i<total_alunos_r; i++) {
                                    printf("\n%s", aluno_reprovados[i].nome);
                                }

                                break;
                            
                            case '4':
                                break;
                    }
                break;
            
            case '2':
                if (tipo_turma == 1) {

                    taxa_apr_m = (M_aprovados/total_m)*100;
                    taxa_repr_m = 100-taxa_apr_m;

                    taxa_apr_f = (F_aprovados/total_f)*100;
                    taxa_repr_f = 100-taxa_apr_f;

                    taxa_apr_alunos = ((M_aprovados + F_aprovados)/total_alunos_float)*100;
                    taxa_repr_alunos = 100-taxa_apr_alunos;


                    //Exibindo percentual masculino
                    printf("\nTaxa de aprovação masculina: %.2f%%\n", taxa_apr_m);
                    printf("Taxa de reprovação masculina: %.2f%%\n", taxa_repr_m);

                    //Exibindo percentual feminino
                    printf("\nTaxa de aprovação feminina: %.2f%%\n", taxa_apr_f);
                    printf("Taxa de reprovação feminina: %.2f%%\n", taxa_repr_f);

                    //Exibindo percentual da turma (TOTAL)
                    printf("\nTaxa de aprovação da turma: %.2f%%\n", taxa_apr_alunos);
                    printf("Taxa de reprovação da turma: %.2f%%\n", taxa_repr_alunos);


                }else if (tipo_turma == 2) {
                    
                    taxa_apr_m = (M_aprovados/total_m)*100;
                    taxa_repr_m = (1-(taxa_apr_m/100))*100;

                    printf("\nTaxa de aprovação: %.2f%%\n Taxa de reprovação: %.2f%%", taxa_apr_m, taxa_repr_m);

                }else if (tipo_turma == 3) {

                    taxa_apr_f = (F_aprovados/total_f)*100;
                    taxa_repr_f = (1-(taxa_apr_f/100))*100;

                    printf("\nTaxa de aprovação: %.2f%%\n Taxa de reprovação: %.2f%%", taxa_apr_f, taxa_repr_f);

                }else {
                    printf("Oxi");
                    break;
                }
                break;
                    
    
            case '3':
                ocorrencia = false;
                break;
            }
    }
    
    return 0;
}

//Oque falta fazer: Gerar relatorios, Apresentar um menu de opções, Relatorio com aprovados, Relatorio com reprovados

//Opcional se tiver tempo: gerar Estatísticas