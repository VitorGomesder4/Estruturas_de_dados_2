#include <stdio.h>

struct pessoa{
  char array_nome[20];
  int idade;
};

int main(){ 
  struct pessoa p;
    
    //Recebendo Nome
    printf("Digite seu nome: ");
    scanf("%19s", p.array_nome); //não é preciso botar o & antes pois o nome "array_nome" ja funciona como ponteiro
    
    //Recebendo Idade
    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    
    //Exibindo resultado
    printf("Seu nome é: %s", p.array_nome);
    printf("Sua idade é: %d", p.idade);
}