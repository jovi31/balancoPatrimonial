#include "estrutura.h"

void menuInicial(){
    int op;

    do{
        limpaTela();
        printarLinha();
        printf("\t# SISTEMA DE BALAN�O PATRIMONIAL");
        printarLinha();
        printf("\n (1) Criar balan�o");
        printf("\n (2) Abrir balan�o");
        printf("\n (3) Deletar balan�o");
        printf("\n (4) Sair\n");
        printarLinha();
        printf("\n -> Escolha uma op��o: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                limpaTela();
                criarBalanco();
                printf("\n -> Arquivo criado com sucesso!\n\n");
                system("PAUSE");
                break;
            case 2:
                abrirBalanco();
                break;
            case 3:
                limpaTela();
                deletarArquivo();
                printf("\n -> Arquivo deletado com sucesso!\n\n");
                system("PAUSE");
                break;
            case 4:
                printf("\n -> Saindo do sistema...\n\n");
                system("PAUSE");
                break;
            default:
                printf("\n -> Op��o inv�lida!\n\n");
                system("PAUSE");
                break;
        }
    }while(op != 4);
}

//Fun��es e Procedimentos

void lerNomeBalanco(char *nome){
    printf("\n -> Digite o nome do balanco: ");
    scanf("%s", nome);
    getchar();
}

void procurarBalanco(char *nome){

}

Item lerItem(){

}

void lerNomeItem(char *nome){

}

int procurarItem(Item umItem){

}

void inserirItemNoArquivo(Item umItem){

}

void modificarItemNoArquivo(Item umItem){

}

void excluirItem(){

}

void alterarBalanco(){

}

//Principais modulos

void criarBalanco(){
    FILE* arquivo;
    char nomeArquivo[30];

    printarLinha();
    printf("\t# CRIAR BALANCO");
    printarLinha();

    lerNomeBalanco(nomeArquivo);

    arquivo = fopen(nomeArquivo, "w");

    fclose(arquivo);
}

void criarItem(){

}

void abrirBalanco(){
    FILE* arquivo;
    char nomeArquivo[30];
    int op;

    limpaTela();
    printarLinha();
    printf("\t# ABRIR BALANCO");
    printarLinha();

    lerNomeBalanco(nomeArquivo);

    arquivo = fopen(nomeArquivo, "a");

    do{
        op = menuAbrirBalanco();

        switch(op){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(op != 4);

    fclose(arquivo);
}

void deletarArquivo(){
    char nomeArquivo[30];

    printarLinha();
    printf("\t# DELETAR BALANCO");
    printarLinha();

    lerNomeBalanco(nomeArquivo);

    remove(nomeArquivo);
}

int menuAbrirBalanco(){
    int op;

    limpaTela();
    printarLinha();
    printf("\t# EDITAR BALAN�O");
    printarLinha();
    printf("\n (1) Inserir item");
    printf("\n (2) Alterar item");
    printf("\n (3) Deletar item");
    printf("\n (4) Sair\n");
    printarLinha();
    printf("\n -> Escolha uma op��o: ");
    scanf("%d", &op);
    getchar();

    return op;
}

void exibirBalanco(){

}

//Utilidades

void limpaTela(){
    system("cls || clear");
}

void printarLinha(){
    printf("\n+--------------------------------------------------+\n");
}