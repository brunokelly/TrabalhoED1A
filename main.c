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

int GerarSenha();
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
    Cliente cliente;
    int opcao;

    do{
        opcao = ExibirMenu();
    }while(opcao != 0);

    return 0;
}
