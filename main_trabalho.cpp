#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "color.h"
#include "date.h"
#include "texto.h"
#include "stock.h"
using namespace std;

int main() {
	double aporte = 0, rend_anual = 0, investimento = 0;// Inicializando vari�vel de aporte, de rendimento anual esperado e de investimento.
	const int TamVetE = 21; // Inicializando vari�vel do tamanho do vetor est�tico.
	int TamVet = 0; // Inicializando vari�vel de tamanho do vetor din�mico
	cout << fixed; // Define nota��o como ponto flutuante.
	cout.precision(2); // Definindo precis�o de pontos flutuantes para 2 casas.
	CorTexto(" Carteira de A��es \n\n", preto, verde); //Gerando texto colorido.

	CorTexto("Quantidade de empresas [ ]\b\b", roxo, preto); //Gerando texto colorido.
	
	cin >> TamVet; //Recebendo quantidade de empresas, que vai ser passado para tamanho do vetor din�mico.
	cin.ignore(); //Ignora o \n do enter para que n�o interrompa o cin.getline mais � frente.
	empresa* empresas = new empresa[TamVet]; // Cria��o do vetor din�mico de empresas com o tamanho definido pelo usu�rio.
	
	GerarLinha(30, '-', roxo, preto); //Gerando linhas de tra�os coloridas.
	cout << endl;

	for (int i = 0; i < TamVet; i++) { // La�o para adicionar conte�do sobre empresas e transa��es no vetor din�mico.
		CorTexto("Empresa: ", roxo, preto);
		cin.getline(empresas[i].nome, 30); //Adiciona nome da empresa em uma posi��o do vetor.
		CorTexto("Ticker: ", roxo, preto);
		cin.getline(empresas[i].codigo, 30); //Adiciona o c�digo da empresa em uma posi��o do vetor.
		Capital(empresas[i].codigo); //Define as letras min�sculas do c�digo da empresa para mai�sculas.
		CorTexto("Transa��es: ", roxo, preto);
		cin >> empresas[i].transacao; //Adiciona a quantidade de transa��es em uma posi��o do vetor.
		cin.ignore(); //Ignora o \n do enter para que n�o interrompa o cin.getline
		GerarLinha(30, '-', roxo, preto); //Gerando linhas de tra�os coloridas.
		cout << endl;
	}

	CorTexto("Transa��es Realizadas", preto, verde); // Texto colorido.
	
	cout << endl << endl;

	for (int i = 0; i < TamVet; i++) { // La�o que percorre uma quantidade de vezes igual � quantidade de empresas.
		transa��es* transaction = new transa��es[empresas[i].transacao]; // Cria��o do vetor din�mico de transa��o da empresa, com tamanho definido pela quantidade de transa��es feitas.
		empresas[i].ponteiro = transaction; // Aloca��o do endere�o do vetor de transa��es no ponteiro da empresa.

		for (int j = 0; j < (empresas[i].transacao); j++) { // La�o aninhado que percorre quantidade igual � de transa��es feitas por cada empresa

			CorTexto(empresas[i].nome, roxo, preto); cout << " - "; CorTexto(empresas[i].codigo, roxo, preto); // Nome da empresa - c�digo.
			cout << endl << endl;

			CorTexto("Data: ", roxo, preto);
			cin >> transaction[j].datas; // Usu�rio define data da transa��o.

			CorTexto("Quantidade: ", roxo, preto);
			cin >> transaction[j].quantidade; // Usu�rio define quantidade comprada.

			CorTexto("Pre�o: ", roxo, preto);
			cin >> transaction[j].preco; // Usu�rio define pre�o de cada compra.
			cout << endl;

		}
	}
	GerarLinha(72, '-', roxo, preto); //Gerando linhas de tra�os coloridas.
	cout << endl;

	investimento = ResCarteira(empresas, TamVet); // Define valor para investimento total chamando fun��o ResCarteira, que vai gerar tabela de Resumo da Carteira.

	GerarLinha(72, '-', roxo, preto); //Gerando linhas de tra�os coloridas.
	cout << endl;

	CorTexto("Aporte anual R$[    ]\b\b\b\b\b", roxo, preto);
	cin >> aporte; // Recebe valor de aporte anual pelo usu�rio.
	CorTexto("Rendimento anual estimado [  ]%\b\b\b\b", roxo, preto);
	cin >> rend_anual; // Recebe valor de rendimento anual esperado pelo usu�rio.
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
	CorTextoAlinhado_dir("Gr�fico", preto, verde, 7);
	GerarLinha(18, ' ', preto, verde);
	cout << endl;
	//Inicializando vetores est�ticos.
	double investidos[TamVetE] = { investimento }; // Inicializa vetor est�tico de investimentos.
	double rendimento[TamVetE] = {}; // Inicializa vetor est�tico de rendimentos.
	double acumulado[TamVetE] = { investimento }; // Inicializa vetor est�tico de acumulados.
	int normal_acumulado[TamVetE] = {}; // Inicializa vetor est�tico de acumulados normalizado.
	char quadrado[3] = { char(254), ' ', '\0'}; // Inicializa vetor de caracteres que contem o quadrado a ser imprimido no gr�fico.

	for (int i = 1; i < TamVetE; i++) { // La�o partindo do ano 1, pois elementos do ano 0 j� foram inicializados.
		rendimento[i] = (acumulado[i-1]+aporte) * (rend_anual / 100); // Atribui��o dos valores com o c�lculo do rendimento segundo pdf.
		acumulado[i] = acumulado[i - 1] + aporte + rendimento[i]; // Atribui��o dos valores com o c�lculo do acumulado segundo pdf.
		investidos[i] = investidos[i-1] + aporte; // Atribui��o dos valores com o c�lculo de investimento segundo pdf.
	}
	for (int i = 0; i < TamVetE; i++) { // La�o para realizar atribui��o dos elementos do vetor normalizado.
		if ((acumulado[i]/acumulado[TamVetE-1]) < 1){ // Verifica se o elemento normalizado � de valor cheio (1) ou menor que 1, para realizar arredondamento de valores.
			normal_acumulado[i] = ((acumulado[i]/acumulado[TamVetE-1])*21)+1;
		}
		else {
			normal_acumulado[i] = ((acumulado[i]) / (acumulado[TamVetE - 1])*21); // Quando valor � igual a 1 (�ltimo elemento do vetor), s� mant�m o c�lculo igual.
		}
	}
	for (int i = 0; i < TamVetE; i++) {
		// Gerando as linhas da tabela.
		CorTextoAlinhado_int(i, preto, verde, 4);
		CorTextoAlinhado_float(investidos[i], verde, preto, 11);
		CorTextoAlinhado_float(rendimento[i], verde, preto, 12);
		CorTextoAlinhado_float(acumulado[i], verde, preto, 12);
		GerarLinha(8, ' ', preto, preto); //
		
		// Gerando os quadrados do gr�fico.
		for (int j = 0; j < TamVetE; j++) { // La�o para percorrer o vetor de acumulados normalizado e fazer a coloca��o dos quadrados no local certo.
			if (normal_acumulado[j] >= (TamVetE-i)) { // IF verificando se a altura bate com o valor do elemento do acumulado normalizado.
				CorTextoAlinhado_dir(quadrado, verde, preto, 1); // Imprime o quadrado referente as posi��es do gr�fico.
			}
			else {
				cout << "  "; // Caso a altura n�o bata com o valor, a posi��o � preenchida com espa�os.
			}
			
		}
		cout << endl;
	}
	GerarLinha(89, '-', verde, preto);

	for (int i = 0; i < TamVet; i++) { // Laco para dele��o dos vetores din�micos para evitar vazamento de mem�ria.
		delete[] empresas[i].ponteiro;
	}
	delete[] empresas;
}
