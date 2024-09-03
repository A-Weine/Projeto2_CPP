#pragma once
#include "date.h"

struct transações { // Define o tipo transações
	dates datas;
	int quantidade;
	float preco;
};

struct empresa { // Define o tipo empresas
	char nome[30];
	char codigo[6];
	int transacao;
	transações* ponteiro; // Define o ponteiro que vai receber a localização do vetor dinamico de transações.
};

//Resumo da Carteira
float ResCarteira(empresa[], int); // Função para imprimir resumo da carteira.