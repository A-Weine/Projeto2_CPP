#pragma once
#include "date.h"

struct transa��es { // Define o tipo transa��es
	dates datas;
	int quantidade;
	float preco;
};

struct empresa { // Define o tipo empresas
	char nome[30];
	char codigo[6];
	int transacao;
	transa��es* ponteiro; // Define o ponteiro que vai receber a localiza��o do vetor dinamico de transa��es.
};

//Resumo da Carteira
float ResCarteira(empresa[], int); // Fun��o para imprimir resumo da carteira.