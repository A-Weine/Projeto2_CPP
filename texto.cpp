#include <iostream>
#include <cstring>
#include "texto.h"
using namespace std;


void CorTexto(const char cvetor[], unsigned short corL, unsigned short corF) { // Função que imprime um texto recebido com a cor desejada.
	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	cout << cvetor; // Imprime vetor com as cores desejadas.

	cout << "\033[m"; // Retorna para cor padrão.

}
// AJEITAR A QUESTÃO DAS CORES MUDAREM O ALINHAMENTO
void CorTextoAlinhado_esq(const char cvetor[], unsigned short corL, unsigned short corF, unsigned int espacos) {

	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	cout.width(espacos); // Define largura do texto.
	cout << left;
	cout << cvetor; // Imprime vetor com as cores desejadas.

	cout << "\033[m"; // Retorna para cor padrão.

}
void CorTextoAlinhado_dir(const char cvetor[], unsigned short corL, unsigned short corF, unsigned int espacos) {

	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	cout.width(espacos); // Define largura do texto.
	cout << right;
	cout << cvetor; // Imprime vetor com as cores desejadas.

	cout << "\033[m"; // Retorna para cor padrão.

}

void CorTextoAlinhado_int(int inteiro, unsigned short corL, unsigned short corF, unsigned int espacos) {

	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	cout.width(espacos); // Define largura do texto.
	cout << right;
	cout << inteiro; // Imprime vetor com as cores desejadas.

	cout << "\033[m"; // Retorna para cor padrão.

}

void CorTextoAlinhado_float(double flutuante, unsigned short corL, unsigned short corF, unsigned int espacos) {

	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	cout.width(espacos); // Define largura do texto.
	cout << right;
	cout << flutuante; // Imprime vetor com as cores desejadas.

	cout << "\033[m"; // Retorna para cor padrão.

}
// ===========================================================================================================

void GerarLinha(unsigned char quantidade, unsigned char caracter, unsigned short corL, unsigned short corF) { // Função que gera linhas de caracteres específicos da cor desejada.

	cout << "\033[38;5;" << corL << "m"; // Ajusta cor das letras do terminal para a cor desejada.
	cout << "\033[48;5;" << corF << "m"; // Ajusta cor do fundo do terminal para a cor desejada.

	while ((quantidade-- > 0)) { // Abre um laço que vai rodar a quantidade necessária para imprimir o tamanho da linha solicitada.
		cout << caracter; // Imprime caractere.
	}

	cout << "\033[m"; // Retorna para cor padrão.
}

void Capital(char cvetor[]) { // Função para deixar um vetor string com letras maiúsculas.
	for (int i = 0; i <= strlen(cvetor); i++) { // Abre um laço que funciona de acordo com a quantidade de caracteres no vetor string
		if (cvetor[i] >= 97 && cvetor[i] <= 122) { // Verifica se o caractere é uma letra minúscula.
			cvetor[i] -= 32; // Converte a letra minúscula para maiúscula seguindo a tabela ASCII.
		}
		else {
			continue; // Caso o caractere não seja uma letra minúscula, o código continua sem fazer nada.
		}
	}
}