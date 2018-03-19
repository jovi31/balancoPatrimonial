typedef struct{
    char nome[30];
    char tipo[4];
    float valor;
    int ehVisivel;
}Item;

//Menus

void menuInicial();
int menuAbrirBalanco();
void exibirTipos();

//Funções e Procedimentos

void lerNomeBalanco(char *nome);
Item lerItem();
void exibirItem(Item umItem);
void lerNomeItem(char *nome);
int selecionarItem(char nomeBalanco[]);          // FUNCAO NOVA
void criarItem(char *nomeArquivo);
void modificarItemNoArquivo(char nomeBalanco[]);
void excluirItem(char nomeBalanco[]);
int ehAtivo(char *tipo);
int ehPassivo(char *tipo);
int ehPatrimonio(char *tipo);

// Principais módulos

void criarBalanco();
void abrirBalanco();
void deletarArquivo();
void inserirItemM(char nomeBalanco[]);
void alterarItemM(char nomeBalanco[]);
void removerItemM(char nomeBalanco[]);
void exibirBalanco(char nomeBalanco[]);

//Utilidades

void limpaTela();
void printarLinha();
void pausar();
