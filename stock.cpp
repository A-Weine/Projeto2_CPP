#include <iostream>
#include "stock.h"
#include "texto.h"
#include "color.h"
using namespace std;

float ResCarteira(empresa empresas[], int TamVet) {
	float preco_m = 0, investido_tmp = 0, total_investido = 0; // Inicializando vari�vel de pre�o m�dio, valor investido, e total investido.
	int quantidades = 0; // Inicializando vari�vel referente � quantidade de a��es compradas.
	GerarLinha(27, ' ', preto, verde); // Est�tica
	CorTexto("Resumo da Carteira", preto, verde);
	GerarLinha(27, ' ', preto, verde); // Est�tica
	cout << endl;

	GerarLinha(72, '-', roxo, preto); // Gerando linhas de -
	cout << endl;
	
	//Exibindo categ�rias com alinhamento e cores definidas.
	CorTextoAlinhado_esq("Empresa", preto, verde, 14);
	CorTextoAlinhado_dir("Ticker", preto, verde, 15);
	CorTextoAlinhado_dir("Qtd.", preto, verde, 11);
	CorTextoAlinhado_dir("Pre�o M�dio", preto, verde, 17);
	CorTextoAlinhado_dir("Investido", preto, verde, 15);
	cout << endl;
	//
	for (int i = 0; i < TamVet; i++) { //Abrindo la�o para percorrer vetor de empresas e imprimir suas informa��es e quantidades das transa��es.
		for (int j = 0; j < empresas[i].transacao; j++) {
			quantidades += (empresas[i].ponteiro+j)->quantidade;
			investido_tmp += ((empresas[i].ponteiro + j)->quantidade * (empresas[i].ponteiro + j)->preco);
		}
		preco_m = investido_tmp/quantidades; // C�lculo para pre�o m�dio
		total_investido += investido_tmp; // Soma para total investio
		CorTextoAlinhado_esq(empresas[i].nome, roxo, preto, 14); // Imprime nome da empresa
		CorTextoAlinhado_dir(empresas[i].codigo, roxo, preto, 15); // Imprime c�digo da empresa
		CorTextoAlinhado_int(quantidades, roxo, preto, 11); // Imprime quantidade de a��es compradas.
		CorTextoAlinhado_float(preco_m, roxo, preto, 17); // Imprime pre�o m�dio
		CorTextoAlinhado_float(investido_tmp, roxo, preto, 15); // Imprime investimento feito na empresa
		cout << endl;
		// Reinicializa��o das vari�veis para 0, visto que seus valores atuais n�o ser�o mais necess�rios.
		preco_m = 0;
		investido_tmp = 0;
		quantidades = 0;
	}
	GerarLinha(72, '-', roxo, preto); // Gerando linhas de -
	cout << endl;
	CorTextoAlinhado_esq("Total Investido:", preto, verde, 16);
	CorTextoAlinhado_float(total_investido, preto, verde, 56); // Imprime total investido.
	cout << endl;

	return total_investido; // Retorna valor total investido.
}