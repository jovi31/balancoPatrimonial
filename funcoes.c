#include "estrutura.h"

void menuInicial(){
    int op;

    do{
        limpaTela();
        printarLinha();
        printf("\t# SISTEMA DE BALANÇO PATRIMONIAL");
        printarLinha();
        printf("\n (1) Criar balanço");
        printf("\n (2) Abrir balanço");
        printf("\n (3) Deletar balanço");
        printf("\n (4) Sair\n");
        printarLinha();
        printf("\n -> Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &op);

        switch(op){
            case 1:
                limpaTela();
                criarBalanco();
                printf("\n -> Arquivo criado com sucesso!\n");
                pausar();
                break;
            case 2:
                abrirBalanco();
                break;
            case 3:
                limpaTela();
                deletarArquivo();
                printf("\n -> Arquivo deletado com sucesso!\n");
                pausar();
                break;
            case 4:
                printf("\n -> Saindo do sistema...\n");
                pausar();
                break;
            default:
                printf("\n -> Opção inválida!\n");
                pausar();
                break;
        }
    }while(op != 4);
}

//Funções e Procedimentos

void lerNomeBalanco(char *nome){
    printf("\n -> Digite o nome do balanco: ");
    scanf("%s", nome);
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
    int op, arquivoValido;

    do{
        limpaTela();
        printarLinha();
        printf("\t# ABRIR BALANCO");
        printarLinha();

        lerNomeBalanco(nomeArquivo);

        arquivo = fopen(nomeArquivo, "r");

        if(arquivo == NULL){
            arquivoValido = 0;
        }else{
            arquivoValido = 1;
        }

        if(arquivoValido == 0){
            printf("\n -> Arquivo não encontrado ...\n");
            pausar();
        }

    }while(arquivoValido == 0);


    op = menuAbrirBalanco();

    do{
        switch(op){
            case 1:
                break;
            case 2:
                limpaTela();
                break;
            case 3:
                limpaTela();
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(op != 4);
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
    printf("\t# EDITAR BALANÇO");
    printarLinha();
    printf("\n (1) Inserir item");
    printf("\n (2) Alterar item");
    printf("\n (3) Deletar item");
    printf("\n (4) Sair\n");
    printarLinha();
    printf("\n -> Escolha uma opção: ");
    scanf("%d", &op);
    fflush(stdin);

    return op;
}

void exibirBalanco(char nomeBalanco[]){
    FILE *arquivo = fopen(nomeBalanco, "a");

    limpaTela();


    fclose(arquivo);
}

//Utilidades

void limpaTela(){
    system("cls || clear");
}

void printarLinha(){
    printf("\n+--------------------------------------------------+\n");
}

void pausar(){
    int aux;
    printarLinha();
    printf("-> Digite [ENTER] para continuar ...");
    printarLinha();
    system("read aux");
}
