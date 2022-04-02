/*Faça um programa que implemente um tabela hash, para armazenar números inteiros, usando o armazenamento em listas dinamicamente
encadeadas para o gerenciamento de colisões.
O usuário deve poder incluir quantos elementos desejar no hash.
As opções permitidas para o usuário são:
1 - Inserir um elemento no hash
2 - Retirar um elemento do hash
3 - Buscar um elemento no hash, indicando como saída se o elemento existe ou não no hash
4 - Imprimir todos os elementos do hash.
Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows*/

#include <stdio.h>
#include <stdlib.h>

// tamanho da tabela
#define M 19

// tipo pessoa
typedef struct
{
    int matricula;
    char nome[50];
} Pessoa;

// tipo nó usado na lista encadeada
typedef struct no
{
    Pessoa pessoa;
    struct no *proximo;
} No;

// tipo lista com um ponteiro para o primeiro nó
typedef struct
{
    No *inicio;
    int tam;
} Lista;

Lista *tabela[M];

Pessoa criarPessoa()
{
    Pessoa p;
    system("cls || clear");
    printf("|***************************Pessoa***************************|\n");
    printf("| - Digite o nome da pessoa: ");
    scanf("%*c");
    fgets(p.nome, 50, stdin);
    printf("| - Digite a matricula: ");
    scanf("%d", &p.matricula);
    printf("|************************************************************|\n");
    return p;
}

// imprime uma pessoa
void imprimirPessoa(Pessoa p)
{
    printf("|************************************************************|\n");
    printf("| \tNome: %s\tMatricula: %d\n", p.nome, p.matricula);
    printf("|************************************************************|\n");
}

// cria uma lista vazia e retorna seu endereço na memória
Lista *criarLista()
{
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

void inserirInicio(Pessoa p, Lista *lista)
{
    No *no = malloc(sizeof(No));
    no->pessoa = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

// busca um elemento na lista
No *buscarNo(int mat, No *inicio)
{

    while (inicio != NULL)
    {
        if (inicio->pessoa.matricula == mat)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL; // matricula não encontrada
}

void imprimirLista(No *inicio)
{
    while (inicio != NULL)
    {
        imprimirPessoa(inicio->pessoa);
        inicio = inicio->proximo;
    }
}

// inicializa a tabela com uma lista vazia em cada posição do vetor
void inicializar()
{
    int i;
    for (i = 0; i < M; i++)
        tabela[i] = criarLista();
}

// função de espalhamento
int funcaoEspalhamento(int mat)
{
    return mat % M;
}

// cria uma pessoa e a insere na tabela
void inserTabela()
{
    Pessoa pes = criarPessoa();
    int indice = funcaoEspalhamento(pes.matricula);
    inserirInicio(pes, tabela[indice]);
}

// busca uma pessoa. Seu retorno é um endereço ou NULL
Pessoa *buscarPessoaTabela(int mat)
{
    int indice = funcaoEspalhamento(mat);
    No *no = buscarNo(mat, tabela[indice]->inicio);
    if (no)
        return &no->pessoa;
    else
        return NULL;
}

// imprimir tabela
void imprimirTabela()
{
    int i;
    printf("|************************************************************|\n");
    printf("|                          TABELA                            |\n");
    for (i = 0; i < M; i++)
    {
        printf("| %d Lista tamanho: %d\n ", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("                         FIM TABELA                          |\n");
    printf("|************************************************************|\n");
}

int main()
{
    int op, mat;
    Pessoa *p;

    inicializar();

    do
    {
        printf("|************************************************************|\n");
        printf("|                                                            |\n");
        printf("|               IFPR - Estrutura de Dados                    |\n");
        printf("|                      Tabela Hash                           |\n");
        printf("|                                                            |\n");
        printf("|               1 - Inserir elemento:                        |\n");
        printf("|               2 - Retirar elemento:                        |\n");
        printf("|               3 - Buscar elemento:                         |\n");
        printf("|               4 - Imprimir elementos                       |\n");
        printf("|               0 - Sair                                     |\n");
        printf("|                                                            |\n");
        printf("|************************************************************|\n");
        scanf("%d", &op);
        switch (op)
        {
            case 0:
            {
                system("cls || clear");
                printf("|************************************************************|\n");
                printf("| Saindo.                                                    |\n");
                printf("|************************************************************|\n");
                break;
            }
            case 1:
            {
                
                printf("|************************************************************|\n");
                printf("| Inserir elemento.                                          |\n");
                printf("|************************************************************|\n");
                inserTabela();
                break;
            }

            case 2:
            {
                system("cls || clear");
                printf("|************************************************************|\n");
                printf("| Retira elemento.                                           |\n");
                printf("|************************************************************|\n");
            }
            case 3:
            {
                system("cls || clear");
                printf("|************************************************************|\n");
                printf("| Busca elemento.                                            |\n");
                printf("Qual a matricula a ser buscada?                              |");
                scanf("%d", &mat);
                p = buscarPessoaTabela(mat);
                if (p)
                {
                    printf("| Pessoa encontrada: Matricula: %d\tNome: %s                       |", p->matricula, p->nome);
                    printf("|************************************************************|\n");
                }
                else
                {
                    system("cls || clear");
                    printf("|************************************************************|\n");
                    printf("| Pessoa nao contrada!                                       |\n");
                    printf("|************************************************************|\n");
                }          
                break;
            }

            case 4:
            {
                system("cls || clear");
                printf("|************************************************************|\n");
                printf("| Imprime elementos.                                         |\n");
                printf("|************************************************************|\n");
                imprimirTabela();
                break;
            }

            default:
            {
                system("cls || clear");
                printf("|************************************************************|\n");
                printf("| Opção Invalida, tente novamente.                           |\n");
                printf("|************************************************************|\n");
                break;
            }
        }
    } while (op != 0);

    return 0;
}