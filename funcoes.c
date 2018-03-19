#include<stdio.h>
#include "estrutura.h"

// Menus

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

void exibirTipos(){
    printarLinha();
    printf("\t# TIPOS DE ITENS NO BALANÇO");
    printarLinha();
    printf("\n\tAC - Ativo Circulante");
    printf("\n\tANC - Ativo Não Circulante");
    printf("\n\tPC - Passivo Circulante");
    printf("\n\tPNC - Passivo Não Circulante");
    printf("\n\tPL - Patrimônio Líquido\n");
    printarLinha();
}

//Funções e Procedimentos

void lerNomeBalanco(char *nome){
    printf("\n -> Digite o nome do balanco: ");
    scanf("%s", nome);
    getchar();
}

Item lerItem(){
    Item umItem;

    printf("\n -> Digite o nome: ");
    scanf("%[^\n]s", umItem.nome);
    getchar();
    exibirTipos();
    printf("\n -> Digite o tipo: ");
    scanf("%s", umItem.tipo);
    getchar();
    printf("\n -> Digite o valor: ");
    scanf("%f", &umItem.valor);
    getchar();
    printf("\n -> Digite a visibilidade: ");
    scanf("%d", &umItem.ehVisivel);
    getchar();
    //umItem.ehVisivel = 1;

    return umItem;
}

void exibirItem(Item umItem){
    printf("\n Nome: %s", umItem.nome);
    printf("\n Tipo: %s", umItem.tipo);
    printf("\n Valor: %.2f\n\n", umItem.valor);
}

void lerNomeItem(char *nome){

}

int selecionarItem(char nomeBalanco[]){
    FILE *arquivo = fopen(nomeBalanco, "rb");
    Item umItem;
    int contadorExibido = 0, contadorReal = 0, posicao[255], op;

    limpaTela();

    printarLinha();
    printf("\t# ITENS DESSE BALANÇO");
    printarLinha();

    fread(&umItem, sizeof(Item), 1, arquivo);

    while(!feof(arquivo)){
        contadorReal++;
        if(umItem.ehVisivel == 1){
            printf("\n (%d) %s [%s]", contadorExibido, umItem.nome, umItem.tipo);
            posicao[contadorExibido] = contadorReal;
            contadorExibido++;
        }
        fread(&umItem, sizeof(Item), 1, arquivo);
    }

    fclose(arquivo);

    printarLinha();
    printf("\n -> Digite o número do item: ");
    scanf("%d", &op);

    return posicao[op] - 1;
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

void modificarItemNoArquivo(char nomeBalanco[]){
    FILE *arquivo = fopen(nomeBalanco, "rb+");
    Item umItem;
    int posicao = selecionarItem(nomeBalanco);

    fseek(arquivo, sizeof(Item) * posicao, SEEK_SET);

    fread(&umItem, sizeof(Item), 1, arquivo);

    printf("\n-> Nome do item: %s", umItem.nome);

    getchar();
    pausar();

    fclose(arquivo);
}

void excluirItem(char nomeBalanco[]){
    Item umItem;
    FILE *arquivo = fopen(nomeBalanco, "rb+");
    int pos = selecionarItem(nomeBalanco);

    fseek(arquivo, sizeof(Item) * pos, SEEK_SET);
    fread(&umItem, sizeof(Item), 1, arquivo);
    fseek(arquivo, sizeof(Item) * pos, SEEK_SET);
    umItem.ehVisivel = 0;
    fwrite(&umItem, sizeof(Item), 1, arquivo);
    fseek(arquivo, 0, SEEK_END);
    fclose(arquivo);
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

    fclose(arquivo);

    do{
        op = menuAbrirBalanco();
        switch(op){
            case 1:
                inserirItemM(nomeArquivo);
                break;
            case 2:
                alterarItemM(nomeArquivo);
                break;
            case 3:
                removerItemM(nomeArquivo);
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

void exibirBalanco(char nomeBalanco[]){
    float totAtivo = 0;
    float totPassivo = 0;
    float totPatrimonio = 0;
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
        if(umItem.ehVisivel){
            if(ehAtivo(umItem.tipo)){
                totAtivo += umItem.valor;
            }
            if(ehPassivo(umItem.tipo)){
                totPassivo += umItem.valor;
            }
            if(ehPatrimonio(umItem.tipo)){
                totPatrimonio += umItem.valor;
            }
            printf("ITEM %d\n", numero + 1);
            exibirItem(umItem);
            numero++;
        }
        fread(&umItem, sizeof(Item), 1, arquivo);
    }

    printarLinha();
    printf(" Total Ativo: %.2f\n", totAtivo);
    printf(" Total Passivo: %.2f\n", totPassivo);
    printf(" Patrimonio Líquido: %.2f\n", totPatrimonio);
    printf(" PL + Passivo = %.2f\n", totPassivo + totPatrimonio);
    printarLinha();

    pausar();

    fclose(arquivo);
}

void inserirItemM(char nomeBalanco[]){
    criarItem(nomeBalanco);
    printarLinha();
    pausar();
}

void alterarItemM(char nomeBalanco[]){
    modificarItemNoArquivo(nomeBalanco);
}

void removerItemM(char nomeBalanco[]){
    excluirItem(nomeBalanco);
}

int ehAtivo(char *tipo){
    if(!strcmp(tipo, "AC") || !strcmp(tipo, "ANC")){
        return 1;
    }else{
        return 0;
    }
}

int ehPassivo(char *tipo){
    if(!strcmp(tipo, "PC") || !strcmp(tipo, "PNC")){
        return 1;
    }else{
        return 0;
    }
}

int ehPatrimonio(char *tipo){
    if(!strcmp(tipo, "PL")){
        return 1;
    }else{
        return 0;
    }
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
    printf("\n -> Digite [ENTER] para continuar ...\n");
    printarLinha();
    aux = getchar();
}
