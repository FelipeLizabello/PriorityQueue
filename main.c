#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
    int dia,mes,ano;
}DATA;

typedef struct{
	char nome[MAX];
	DATA data;
    float valor;
    int gravidade;
}PACIENTE;

int verifica_Data(int dia, int mes, int ano){
       
    if(dia>31 || dia<1)
        return -1;
    else if(mes<1 || mes>12)
        return -1;
    else if(ano<1900 || ano>2025)
        return -1;
    else 
        return 0;

}

void inserir(int *n, PACIENTE paciente[]){
	int i;
	PACIENTE aux;
	
	printf("\nDigite os dados do paciente:\n");
	
    printf("Nome\n");
    getchar();
    fgets(aux.nome, MAX, stdin);
    aux.nome[strcspn(aux.nome, "\n")] = '\0';
	
    do{
    printf("Coloque a data de nascimento \n");
    scanf("%d %d %d", &aux.data.dia, &aux.data.mes, &aux.data.ano);
    }while(verifica_Data(aux.data.dia, aux.data.mes, aux.data.ano) == -1);
    
    printf("Valor da consulta\n");
    scanf ("%f",&aux.valor);
    
    printf("Gravidade:\n 1-leve\n 2-medio\n 3-grave\n");
    scanf ("%d",&aux.gravidade);
	
	for(i=(*n)-1; i>=0 && aux.gravidade>paciente[i].gravidade; i--)
		paciente[i+1] = paciente[i];
					
	paciente[++i] = aux;
	(*n)++;
}

void mostrar(int n, PACIENTE paciente[]){
	int i;
	
    printf("\n=== Lista de Pacientes ===\n");
        for(i = 0; i < n; i++){
            printf("Nome: %s\t", paciente[i].nome);
            printf("Data de Nascimento: %d/%d/%d\t", paciente[i].data.dia, paciente[i].data.mes, paciente[i].data.ano);
            printf("Gravidade: %d\t", paciente[i].gravidade);
            printf("Valor: %.2f\n", paciente[i].valor);
        }
}

int main(){
	int n=0;
	PACIENTE paciente[MAX];
	int opcao;
	
	do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir paciente\n");
        printf("2. Mostrar paciente\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
	 	
		 switch(opcao) {
            case 1:
                if (n < MAX) {
                    inserir(&n, paciente);
                } else {
                    printf("Limite de pacientes atingido!\n");
                }
                break;
            case 2:
                mostrar(n, paciente);
                break;
            case 3:
                printf("Saindo... :(\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 3);
}	


