#include <iostream>
#include "stock.h"
#include "texto.h"
#include "color.h"
using namespace std;

float ResCarteira(empresa empresas[], int TamVet) {
	float preco_m = 0, investido_tmp = 0, total_investido = 0; // Inicializando variável de preço médio, valor investido, e total investido.
	int quantidades = 0; // Inicializando variável referente à quantidade de ações compradas.
	GerarLinha(27, ' ', preto, verde); // Estética
	CorTexto("Resumo da Carteira", preto, verde);
	GerarLinha(27, ' ', preto, verde); // Estética
	cout << endl;

	GerarLinha(72, '-', roxo, preto); // Gerando linhas de -
	cout << endl;
	
	//Exibindo categórias com alinhamento e cores definidas.
	CorTextoAlinhado_esq("Empresa", preto, verde, 14);
	CorTextoAlinhado_dir("Ticker", preto, verde, 15);
	CorTextoAlinhado_dir("Qtd.", preto, verde, 11);
	CorTextoAlinhado_dir("Preço Médio", preto, verde, 17);
	CorTextoAlinhado_dir("Investido", preto, verde, 15);
	cout << endl;
	//
	for (int i = 0; i < TamVet; i++) { //Abrindo laço para percorrer vetor de empresas e imprimir suas informações e quantidades das transações.
		for (int j = 0; j < empresas[i].transacao; j++) {
			quantidades += (empresas[i].ponteiro+j)->quantidade;
			investido_tmp += ((empresas[i].ponteiro + j)->quantidade * (empresas[i].ponteiro + j)->preco);
		}
		preco_m = investido_tmp/quantidades; // Cálculo para preço médio
		total_investido += investido_tmp; // Soma para total investio
		CorTextoAlinhado_esq(empresas[i].nome, roxo, preto, 14); // Imprime nome da empresa
		CorTextoAlinhado_dir(empresas[i].codigo, roxo, preto, 15); // Imprime código da empresa
		CorTextoAlinhado_int(quantidades, roxo, preto, 11); // Imprime quantidade de ações compradas.
		CorTextoAlinhado_float(preco_m, roxo, preto, 17); // Imprime preço médio
		CorTextoAlinhado_float(investido_tmp, roxo, preto, 15); // Imprime investimento feito na empresa
		cout << endl;
		// Reinicialização das variáveis para 0, visto que seus valores atuais não serão mais necessários.
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