#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

//Variáveis globais
char palavrasecreta[CARACTERES_PALAVRA], chutes[26];
int chutesdados = 0;


void abertura() {
	printf("     _                         _         _____                               \n");
	printf("    | | ___   __ _  ___     __| | __ _  |  ___|__  _ __ ___ __ _             \n");
	printf(" _  | |/ _ \\ / _` |/ _ \\   / _` |/ _` | | |_ / _ \\| '__/ __/ _` |         \n");
	printf("| |_| | (_) | (_| | (_) | | (_| | (_| | |  _| (_) | | | (_| (_| |            \n");
	printf(" \\___/ \\___/ \\__, |\\___/   \\__,_|\\__,_| |_|  \\___/|_|  \\___\\__,_|   \n");
	printf("             |___/                                                           \n");
}

void chuta() {
	char chute;
	printf("\nChute uma letra: ");
	scanf(" %c", &chute);
	chute = toupper(chute);
	printf("\n");
	
	chutes[chutesdados] = chute;
	chutesdados++;

}

void imprimepalavra() {
	for (int i = 0; i < strlen(palavrasecreta); i++) {
			
		int achou = achouletra(palavrasecreta[i]);

		if (achou) {
			printf("%c ", palavrasecreta[i]);
		} else {
			printf("_ ");
		}
	}
	printf("\n");
}

int achouletra(char letra) {
	int achou = 0;

	for (int j = 0; j < chutesdados; j++) {
		if (chutes[j] == letra) {
			achou = 1;
			break;
		}
	}
	return achou;
}

void secreto() {
	FILE* f;
	f = fopen("palavras.txt", "r");
	if (f == 0) {
		printf("Desculpe, banco de dados indisponivel!\n\n");
		exit(1);
	}

	int qtdpalavras;
	fscanf(f, "%d", &qtdpalavras);

	srand(time(0));
	int randomico = rand() % qtdpalavras;

	for (int i = 0; i <= randomico; i++) {
		fscanf(f, "%s", palavrasecreta);
	}

	fclose(f);
}

int acertou() {
	for (int i = 0; i < strlen(palavrasecreta); i++) {
		if (!achouletra(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

int enforcou() {
	return erros() >= 5;
}

int erros() {
	int errou = 0;
	for (int i = 0; i < chutesdados; i++) {
		int existe = 0;

		for (int j = 0; j < strlen(palavrasecreta); j++) {
			if(chutes[i] == palavrasecreta[j]) {
				existe = 1;
				break;
			}
		}
		if (!existe) errou++;
	}
	return errou;
}

void adicionaplvr() {
	char opcao;
	printf("Quer adicionar uma palavra ao banco de dados? (S/N)");
	scanf(" %c", &opcao);
	opcao = toupper(opcao);

	if (opcao == 'S') {
		char palavra[CARACTERES_PALAVRA];
		printf("Escreva a palavra: ");
		scanf("%s", palavra);

		FILE* f;
		f = fopen("palavras.txt", "r+");
		if (f == 0) {
			printf("Ñao foi possivel adicionar a palavra! Banco de dados offline.\n\n");
			exit(1);
		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;

		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", palavra);

		fclose(f);
		printf("Palavra adicionada com sucesso!\n");

	}
}

void vitoria() {
	printf("  __   _____  _   _  __        _____ _   _ _         \n");
	printf("  \\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | | |  \n");
	printf("   \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| | |   \n");
	printf("    | || |_| | |_| |   \\ V  V /  | || |\\  |_|      \n");
	printf("    |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_(_)   \n");
	printf("                ___________                    		 \n");
	printf("               '._==_==_=_.'                         \n");
	printf("               .-\\:      /-.                        \n");
	printf("              | (|:.     |) |                        \n");
	printf("               '-|:.     |-'                         \n");
	printf("                 \\::.    /                          \n");
	printf("                  '::. .'                            \n");
	printf("                    ) (                              \n");
	printf("                  _.' '._                            \n");
	printf("                 '-------'                           \n\n");

}

void derrota() {
	printf("  ____    _    __  __ _____    _____     _______ ____  _          \n");
	printf(" / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\| |    \n");
	printf("| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) | |     \n");
	printf("| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ <|_|       \n");
	printf(" \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_(_)   \n");
	printf("                       _______________                            \n");        
	printf("                      /               \\                          \n");      
	printf("                     /                 \\                         \n");  
	printf("                   //                   \\/\\                     \n");
	printf("                   \\|   XXXX     XXXX   | /                      \n");
	printf("                    |   XXXX     XXXX   |/                        \n");
	printf("                    |   XXX       XXX   |                         \n");
	printf("                    |                   |                         \n");
	printf("                    \\__      XXX      __/                        \n");
	printf("                      |\\     XXX     /|                          \n");
	printf("                      | |           | |                           \n");
	printf("                      | I I I I I I I |                           \n");
	printf("                      |  I I I I I I  |                           \n");
	printf("                      \\_             _/                          \n");
	printf("                        \\_         _/                            \n");
	printf("                          \\_______/                              \n\n");
	printf("A palavra era %s \n\n", palavrasecreta);
}

void forca() {
	int enforca = erros();

	printf("  _______          \n");
	printf(" |/      |         \n");
	printf(" |      %c%c%c     \n", (enforca >= 1 ? '(' : ' '), (enforca >= 1 ? '_' : ' '), (enforca >= 1 ? ')' : ' '));
	printf(" |      %c%c%c     \n", (enforca >= 3 ? '\\' : ' '), (enforca >= 2 ? '|' : ' '), (enforca >= 3 ? '/' : ' '));
	printf(" |       %c        \n", (enforca >= 2 ? '|' : ' '), '/');
	printf(" |      %c %c      \n", (enforca >= 4 ? '/' : ' '), (enforca >= 4 ? '\\' : ' '));
	printf(" |                 \n");
	printf("_|___              \n");
}

int main() {

	secreto(palavrasecreta);

	abertura();

	do {
		forca();
		imprimepalavra();
		chuta();


	} while (!acertou() && !enforcou());

	if (acertou()) {
		vitoria();
	} else {
		derrota();
	}

	adicionaplvr();

}