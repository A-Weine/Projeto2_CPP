#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "color.h"
#include "date.h"
#include "texto.h"
#include "stock.h"
using namespace std;

int main() {
	double aporte = 0, rend_anual = 0, investimento = 0;// Inicializando variável de aporte, de rendimento anual esperado e de investimento.
	const int TamVetE = 21; // Inicializando variável do tamanho do vetor estático.
	int TamVet = 0; // Inicializando variável de tamanho do vetor dinâmico
	cout << fixed; // Define notação como ponto flutuante.
	cout.precision(2); // Definindo precisão de pontos flutuantes para 2 casas.
	CorTexto(" Carteira de Ações \n\n", preto, verde); //Gerando texto colorido.

	CorTexto("Quantidade de empresas [ ]\b\b", roxo, preto); //Gerando texto colorido.
	
	cin >> TamVet; //Recebendo quantidade de empresas, que vai ser passado para tamanho do vetor dinâmico.
	cin.ignore(); //Ignora o \n do enter para que não interrompa o cin.getline mais à frente.
	empresa* empresas = new empresa[TamVet]; // Criação do vetor dinâmico de empresas com o tamanho definido pelo usuário.
	
	GerarLinha(30, '-', roxo, preto); //Gerando linhas de traços coloridas.
	cout << endl;

	for (int i = 0; i < TamVet; i++) { // Laço para adicionar conteúdo sobre empresas e transações no vetor dinâmico.
		CorTexto("Empresa: ", roxo, preto);
		cin.getline(empresas[i].nome, 30); //Adiciona nome da empresa em uma posição do vetor.
		CorTexto("Ticker: ", roxo, preto);
		cin.getline(empresas[i].codigo, 30); //Adiciona o código da empresa em uma posição do vetor.
		Capital(empresas[i].codigo); //Define as letras minúsculas do código da empresa para maiúsculas.
		CorTexto("Transações: ", roxo, preto);
		cin >> empresas[i].transacao; //Adiciona a quantidade de transações em uma posição do vetor.
		cin.ignore(); //Ignora o \n do enter para que não interrompa o cin.getline
		GerarLinha(30, '-', roxo, preto); //Gerando linhas de traços coloridas.
		cout << endl;
	}

	CorTexto("Transações Realizadas", preto, verde); // Texto colorido.
	
	cout << endl << endl;

	for (int i = 0; i < TamVet; i++) { // Laço que percorre uma quantidade de vezes igual à quantidade de empresas.
		transações* transaction = new transações[empresas[i].transacao]; // Criação do vetor dinâmico de transação da empresa, com tamanho definido pela quantidade de transações feitas.
		empresas[i].ponteiro = transaction; // Alocação do endereço do vetor de transações no ponteiro da empresa.

		for (int j = 0; j < (empresas[i].transacao); j++) { // Laço aninhado que percorre quantidade igual à de transações feitas por cada empresa

			CorTexto(empresas[i].nome, roxo, preto); cout << " - "; CorTexto(empresas[i].codigo, roxo, preto); // Nome da empresa - código.
			cout << endl << endl;

			CorTexto("Data: ", roxo, preto);
			cin >> transaction[j].datas; // Usuário define data da transação.

			CorTexto("Quantidade: ", roxo, preto);
			cin >> transaction[j].quantidade; // Usuário define quantidade comprada.

			CorTexto("Preço: ", roxo, preto);
			cin >> transaction[j].preco; // Usuário define preço de cada compra.
			cout << endl;

		}
	}
	GerarLinha(72, '-', roxo, preto); //Gerando linhas de traços coloridas.
	cout << endl;

	investimento = ResCarteira(empresas, TamVet); // Define valor para investimento total chamando função ResCarteira, que vai gerar tabela de Resumo da Carteira.

	GerarLinha(72, '-', roxo, preto); //Gerando linhas de traços coloridas.
	cout << endl;

	CorTexto("Aporte anual R$[    ]\b\b\b\b\b", roxo, preto);
	cin >> aporte; // Recebe valor de aporte anual pelo usuário.
	CorTexto("Rendimento anual estimado [  ]%\b\b\b\b", roxo, preto);
	cin >> rend_anual; // Recebe valor de rendimento anual esperado pelo usuário.
	cout << endl;

	//Tabela de Rendimento da Carteira.
	GerarLinha(32, ' ', preto, verde); CorTextoAlinhado_esq("Rentabilidade da Carteira", preto, verde, 25); GerarLinha(32, ' ', preto, verde);
	cout << endl;
	GerarLinha(89, '-', verde, preto);

	cout << endl;

	//Parte superior da Tabela.
	CorTextoAlinhado_dir("Ano", preto, verde, 4);
	CorTextoAlinhado_dir("Investido", preto, verde, 11);
	CorTextoAlinhado_dir("Rendimento", preto, verde, 12);
	CorTextoAlinhado_dir("Acumulado", preto, verde, 12);
	GerarLinha(25, ' ', preto, verde);
	CorTextoAlinhado_dir("Gráfico", preto, verde, 7);
	GerarLinha(18, ' ', preto, verde);
	cout << endl;
	//Inicializando vetores estáticos.
	double investidos[TamVetE] = { investimento }; // Inicializa vetor estático de investimentos.
	double rendimento[TamVetE] = {}; // Inicializa vetor estático de rendimentos.
	double acumulado[TamVetE] = { investimento }; // Inicializa vetor estático de acumulados.
	int normal_acumulado[TamVetE] = {}; // Inicializa vetor estático de acumulados normalizado.
	char quadrado[3] = { char(254), ' ', '\0'}; // Inicializa vetor de caracteres que contem o quadrado a ser imprimido no gráfico.

	for (int i = 1; i < TamVetE; i++) { // Laço partindo do ano 1, pois elementos do ano 0 já foram inicializados.
		rendimento[i] = (acumulado[i-1]+aporte) * (rend_anual / 100); // Atribuição dos valores com o cálculo do rendimento segundo pdf.
		acumulado[i] = acumulado[i - 1] + aporte + rendimento[i]; // Atribuição dos valores com o cálculo do acumulado segundo pdf.
		investidos[i] = investidos[i-1] + aporte; // Atribuição dos valores com o cálculo de investimento segundo pdf.
	}
	for (int i = 0; i < TamVetE; i++) { // Laço para realizar atribuição dos elementos do vetor normalizado.
		if ((acumulado[i]/acumulado[TamVetE-1]) < 1){ // Verifica se o elemento normalizado é de valor cheio (1) ou menor que 1, para realizar arredondamento de valores.
			normal_acumulado[i] = ((acumulado[i]/acumulado[TamVetE-1])*21)+1;
		}
		else {
			normal_acumulado[i] = ((acumulado[i]) / (acumulado[TamVetE - 1])*21); // Quando valor é igual a 1 (último elemento do vetor), só mantém o cálculo igual.
		}
	}
	for (int i = 0; i < TamVetE; i++) {
		// Gerando as linhas da tabela.
		CorTextoAlinhado_int(i, preto, verde, 4);
		CorTextoAlinhado_float(investidos[i], verde, preto, 11);
		CorTextoAlinhado_float(rendimento[i], verde, preto, 12);
		CorTextoAlinhado_float(acumulado[i], verde, preto, 12);
		GerarLinha(8, ' ', preto, preto); //
		
		// Gerando os quadrados do gráfico.
		for (int j = 0; j < TamVetE; j++) { // Laço para percorrer o vetor de acumulados normalizado e fazer a colocação dos quadrados no local certo.
			if (normal_acumulado[j] >= (TamVetE-i)) { // IF verificando se a altura bate com o valor do elemento do acumulado normalizado.
				CorTextoAlinhado_dir(quadrado, verde, preto, 1); // Imprime o quadrado referente as posições do gráfico.
			}
			else {
				cout << "  "; // Caso a altura não bata com o valor, a posição é preenchida com espaços.
			}
			
		}
		cout << endl;
	}
	GerarLinha(89, '-', verde, preto);

	for (int i = 0; i < TamVet; i++) { // Laco para deleção dos vetores dinâmicos para evitar vazamento de memória.
		delete[] empresas[i].ponteiro;
	}
	delete[] empresas;
}
