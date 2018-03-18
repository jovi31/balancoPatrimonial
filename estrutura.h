typedef struct{
    char nome[30];
    char tipo[4];
    float valor;
    int ehVisivel;
}Item;

//Funções e Procedimentos
void lerNomeBalanco(char *nome);
void procurarBalanco(char *nome);
Item lerItem();
void exibirItem(Item umItem);
void lerNomeItem(char *nome);
int procurarItem(Item umItem);
void inserirItemNoArquivo(Item umItem);
void modificarItemNoArquivo(Item umItem);
void excluirItem();
void alterarBalanco();

//Menus
void menuInicial();
void criarItem(char *nomeArquivo);
void abrirBalanco();
void deletarArquivo();
int menuAbrirBalanco();
void exibirBalanco(char nomeBalanco[]);

//Utilidades
void limpaTela();
void printarLinha();
void pausar();
