#include<stdio.h>
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
        scanf("%d", &op);
        getchar();

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
    getchar();
}

void procurarBalanco(char *nome){

}

Item lerItem(){
    Item umItem;

    printf("\n - > Digite o nome: ");
    scanf("%[^\n]s", umItem.nome);
    getchar();
    printf("\n - > Digite o tipo: ");
    scanf("%s", umItem.tipo);
    getchar();
    printf("\n - > Digite o valor: ");
    scanf("%f", &umItem.valor);
    getchar();
    umItem.ehVisivel = 1;

    return umItem;
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

void criarItem(char *nomeArquivo){
    Item umItem;
    FILE* arquivo = fopen(nomeArquivo, "ab");

    limpaTela();

    printarLinha();
    printf("\t# CRIAR ITEM");
    printarLinha();

    umItem = lerItem();

    fwrite(&umItem, sizeof(Item), 1, arquivo);

    fclose(arquivo);
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

    do{
        op = menuAbrirBalanco();
        switch(op){
            case 1:
                criarItem(nomeArquivo);
                break;
            case 2:
                limpaTela();
                break;
            case 3:
                limpaTela();
                break;
            case 4:
                exibirBalanco(nomeArquivo);
                break;
            case 5:
                break;
            default:
                break;
        }
    }while(op != 5);
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
    printf("\n (4) Exibir balanco");
    printf("\n (5) Sair\n");
    printarLinha();
    printf("\n -> Escolha uma opção: ");
    scanf("%d", &op);
    getchar();

    return op;
}

void exibirItem(Item umItem){
    printf("\n Nome: %s", umItem.nome);
    printf("\n Tipo: %s", umItem.tipo);
    printf("\n Valor: %.2f\n\n", umItem.valor);
}

void exibirBalanco(char nomeBalanco[]){
    int numero = 0;
    Item umItem;
    FILE *arquivo = fopen(nomeBalanco, "rb");

    limpaTela();

    printarLinha();
    printf("\t# ITENS DO BALANÇO");
    printarLinha();

    rewind(arquivo);

    fread(&umItem, sizeof(Item), 1, arquivo);
    while(!feof(arquivo)){
        printf("ITEM %d\n", numero + 1);
        exibirItem(umItem);
        fread(&umItem, sizeof(Item), 1, arquivo);
        numero++;
    }

    pausar();

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
    system("PAUSE");
}
