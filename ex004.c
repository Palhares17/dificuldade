#include "header.h"
#define tam 5

typedef struct {
    char titulo[30];
    char autor[30];
    int ano;
} LIVRO;

void pesquisa(LIVRO *livro, int cont) {
    char tituloPesquisa[30];
    for(int i=0; i<cont; i++) {
        if(strcmp(tituloPesquisa, livro[i].titulo) == 0) {
            printf("%s\n", livro[i].autor);
            printf("%d\n", livro[i].ano);
        }
    }
}

void inserir(LIVRO *livro) {
    FILE *arquivo;
    arquivo = fopen("./arquivos/livros.txt", "a");

    if(arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
        return;
    }

    printf("titulo:");
    scanf("%s", livro->titulo);
    printf("autor:");
    scanf("%s", livro->autor);
    printf("ano:");
    scanf("%d", &livro->ano);

    fprintf(arquivo, "%s %s %d\n", livro->titulo, livro->autor, livro->ano);

    fclose(arquivo);
}

void listar(LIVRO *livro, int cont) {
    FILE *arquivo;
    int i=0;
    arquivo = fopen("./arquivos/livros.txt", "r");

    if(arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
        return;
    }

    while(!feof(arquivo)) {
        printf("%s %s %d\n", livro[i].titulo, livro[i].autor, livro[i].ano);
        i++;
    }

    fclose(arquivo);
}

int main() {
    FILE *livros;
    LIVRO livro[tam];
    int menu;
    int i=0;

    livros = fopen("./arquivos/livros.txt", "r+");
    if(livros == NULL) {
        printf("ERRO AO ABRIR ARQUIVO");
        return 0;
    }

    while(!feof(livros)) {
        fscanf(livros, "%s %s %d", livro[i].titulo, livro[i].autor, &livro[i].ano);

        printf("Pesquisar pelo titulo - 1\nInserir um novo livro - 2\nlistar todos os livros - 3\n");
        printf(">>");
        scanf("%d", &menu);

        if(menu == 1) {
            pesquisa(livro, i);
        }

        if(menu == 2) {
            inserir(livro);
        }

        if(menu == 3) {
            listar(livro, i);
        }

        i++;
    }

    fclose(livros);
    return 0;
}