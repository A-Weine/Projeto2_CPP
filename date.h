#pragma once
#include <iostream>
using namespace std;

struct dates { //Define o tipo dates
	short dia;
	short mes;
	short ano;
};

ostream& operator<<(ostream&, dates&); // Protótipo da função para que cout funcione com os tipo dates

istream& operator>>(istream&, dates&); // Protótipo da função para que cin funcione com os tipo dates