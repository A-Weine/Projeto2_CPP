#pragma once
void GerarLinha(unsigned char quantidade, unsigned char caracter, unsigned short corL, unsigned short corF); // Fun��o para gerar linha de caracteres colorido;

void CorTexto(const char cvetor[], unsigned short corL, unsigned short corF); // Fun��o para alterar cor de texto;

void Capital(char cvetor[]); // Prot�tipo da fun��o que capitaliza vetores de caracteres.

void CorTextoAlinhado_esq(const char cvetor[], unsigned short corL, unsigned short corF, unsigned int espacos); // Fun��o que colore, define tamanho minimo e alinha texto para esquerda

void CorTextoAlinhado_dir(const char cvetor[], unsigned short corL, unsigned short corF, unsigned int espacos); // Fun��o que colore, define tamanho minimo e alinha texto para direita

void CorTextoAlinhado_int(int inteiro, unsigned short corL, unsigned short corF, unsigned int espacos); // Fun��o que colore e define tamanho minimo de inteiros.

void CorTextoAlinhado_float(double flutuante, unsigned short corL, unsigned short corF, unsigned int espacos); // Fun��o que colore e define tamanho minimo de pontos flutuantes.