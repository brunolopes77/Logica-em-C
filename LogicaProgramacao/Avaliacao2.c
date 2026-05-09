#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("Digite um codigo para seu livro: ");
	fgets(codigo, 1000, stdin);

	printf("Titulo: ");
	fgets(titulo, 1000, stdin);

	printf("Autor: ");
	fgets(autor, 1000 , stdin);

	fprintf(arquivo, "Codigo: %s", codigo);
	fprintf(arquivo, "Titulo: %s", titulo);
	fprintf(arquivo, "Autor: %s\n", autor);

	fclose(arquivo);
}

void consultarLivro() {
	char busca[1000];
	char linha[1000];
	int encontrado = 0;

	FILE *arquivo = fopen("dados.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	printf("Digite o codigo do livro que deseja buscar: ");
	fgets(busca, 1000, stdin);

	
	busca[strcspn(busca, "\n")] = '\0';

	while (fgets(linha, 1000, arquivo) != NULL) {

		if (strstr(linha, busca) != NULL) {

			printf("\n=== LIVRO ENCONTRADO ===\n");
			
			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			encontrado = 1;
			break;
		}
	}

	if (!encontrado) {
		printf("Livro nao encontrado.\n");
	}

	fclose(arquivo);
}


void emprestarLivro() {

	char busca[1000];
	char linha[1000];

	FILE *arquivo = fopen("dados.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir arquivo.\n");
		return;
	}

	printf("Digite o codigo do livro: ");
	fgets(busca, 1000, stdin);

	busca[strcspn(busca, "\n")] = '\0';

	int encontrado = 0;

	while (fgets(linha, 1000, arquivo) != NULL) {

		if (strstr(linha, busca) != NULL) {

			encontrado = 1;

			printf("\nLivro encontrado:\n");

			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			printf("Livro emprestado com sucesso!\n");

			break;
		}
	}

	if (!encontrado) {
		printf("Livro nao encontrado.\n");
	}

	fclose(arquivo);
}

void devolverLivro() {

	char busca[1000];
	char linha[1000];

	FILE *arquivo = fopen("dados.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir arquivo.\n");
		return;
	}

	printf("Digite o codigo do livro: ");
	fgets(busca, 1000, stdin);

	busca[strcspn(busca, "\n")] = '\0';

	int encontrado = 0;

	while (fgets(linha, 1000, arquivo) != NULL) {

		if (strstr(linha, busca) != NULL) {

			encontrado = 1;

			printf("\nLivro encontrado:\n");

			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			fgets(linha, 1000, arquivo);
			printf("%s", linha);

			printf("Livro devolvido com sucesso!\n");

			break;
		}
	}

	if (!encontrado) {
		printf("Livro nao encontrado.\n");
	}

	fclose(arquivo);
}

void listarLivros() {
	char linha[1000];

	FILE *arquivo = fopen("dados.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	printf("\n===== LISTA DE LIVROS =====\n\n");

	while (fgets(linha, 1000, arquivo) != NULL) {
		printf("%s", linha);
	}

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
				consultarLivro();
				break;
			case 3:
				emprestarLivro();
				break;
			case 4:
				devolverLivro();
				break;
			case 5:
				listarLivros();
				break;
			default:
				printf("Opcao inexistente.");
				break;
		}
	} while (opcao != 0);

	
	return 0;
}