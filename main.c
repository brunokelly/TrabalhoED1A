#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cliente {
    int senha;
    char tipo; // P = priorit�rio; N = normal.
} Cliente;

typedef struct caixa {
    int senha_corrente;
    char status; // L = livre; O = ocupado; F = Fechado
} Caixa;

void GerarSenhaNormal(Cliente clientes[], int pessoas, int *senhaGerada){
    *senhaGerada = rand() % 20;

    VerificarSeSenhaJaExiste(&senhaGerada, clientes, pessoas);

    clientes[pessoas].senha = *senhaGerada;
    clientes[pessoas].tipo = 'N';
};

void GerarSenhaPrioritaria(Cliente clientes[], int pessoas, int *senhaGerada){
    *senhaGerada = rand() % 20;

    VerificarSeSenhaJaExiste(&senhaGerada, clientes, pessoas);

    clientes[pessoas].senha = *senhaGerada;
    clientes[pessoas].tipo = 'P';
};

void VerificarSeSenhaJaExiste(int *senhaGerada, Cliente clientes[], int pessoas){
    int i = 0;

    for(i = 0; i < pessoas+1; i++){
        if(clientes[i].senha == *senhaGerada){
            *senhaGerada = GerarNumeroSenha(&senhaGerada);
        }
    }
}

int GerarNumeroSenha(int *senhaGerada){
    return *senhaGerada = rand() % 20;
}

int ExibirMenu(){
    int opcao = 1;
    printf("---MENU---\nDigite o a op��o que deseja:\n1 - Gerar senha NORMAL\n2 - Gerar senha PRIORIT�RIA\n3 - Liberar caixa fechado ou ocupado\n4 - Fechar caixa\n0 - Sair do programa\n");
    scanf("%i", &opcao);
    return opcao;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Caixa caixas[5];
    Cliente clientes[40];
    int opcao = 0, pessoas = 0, *senha;

    do{

        opcao = ExibirMenu();

        switch(opcao)
        {
        case 1:
            GerarSenhaNormal(clientes, pessoas, &senha);
            break;
        case 2:
            GerarSenhaPrioritaria(clientes, pessoas, &senha);
            break;
        case 3:
        case 4:
        default:
            break;
        }

        int y;
        for(y = 0; y <= pessoas; y++)
        {
            printf("| %i - %c | ", clientes[y].senha, clientes[y].tipo);
        }
        printf("\n");

        pessoas++;

    }while(opcao != 0);

    return 0;
}
