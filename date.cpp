#include "date.h"

ostream& operator<<(ostream& os, dates& datas) { // Função para que o cout funcione junto dos tipos dates
	os << datas.dia << "/";
	os << datas.mes << "/";
	os << datas.ano;

	return os;
}

istream& operator>>(istream& is, dates& datas) { // Função para que o cin funcione junto dos tipos dates
	cin >> datas.dia;
	cin.ignore();
	cin >> datas.mes;
	cin.ignore();
	cin >> datas.ano;

	return is;
}