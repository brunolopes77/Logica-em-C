#include <stdio.h>
#include <stdlib.h>

int imprimirMenu() {
	int opcao;
	printf("===== BIBLIOTECA =====\n");
	printf("1 - Cadastrar livro\n");
	printf("2 - Consultar livro\n");
	printf("3 - Emprestar livro\n");
	printf("4 - Devolver livro\n");
	printf("5 - Listar livros\n");
	printf("0 - Sair\n");
	printf("Escolha uma das opcoes: ");
	scanf("%i", &opcao);
	getchar();
	return opcao;
}

void criarArquivoLivro() {
	FILE *livro;
	livro = fopen("dados.txt", "a");
	if (livro == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(1);
	}
	printf("Arquivo aberto com sucesso!\n");
	fclose(livro);
}

void cadastrarLivro() {
	char codigo[1000];
	char titulo[1000];
	char autor[1000];
	FILE *arquivo;

	arquivo = fopen("dados.txt", "a"); 

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	printf("Titulo: ");
	fgets(titulo, 1000, stdin);
	fprintf(arquivo, "Titulo: %s", titulo);

	printf("Autor: ");
	fgets(autor, 1000 , stdin);
	fprintf(arquivo, "Autor: %s", autor);

	printf("Digite um codigo para seu livro:");
	fgets(codigo, 1000, stdin);
	fprintf(arquivo, "codigo do livro: %s\n", codigo);
	
	fclose(arquivo);

}

int main() {
	int opcao;
	criarArquivoLivro();

	do {
		opcao = imprimirMenu();

		switch (opcao) {
			case 1:
                cadastrarLivro();
				break;
			case 2:
				break;
		}
	} while (opcao != 0);

	return 0;
}