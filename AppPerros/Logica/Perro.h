/**
 * Project Untitled
 */

#ifndef _PERRO_H
#define _PERRO_H

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Perro {
private: 
    string id;
    tm fechaNacimiento;
    string raza;
    char tamano;
    string tipoConcentrado;
    string idCliente;
public:
	static int idActual;
	Perro(tm f, string r, char tam, string tipoC, string iC){		
		ostringstream ss;		
		Perro::idActual++;
		ss<<idActual;
		id = ss.str();		
		fechaNacimiento = f;
		raza = r;	
		tamano = tam;
		tipoConcentrado = tipoC;
		idCliente = iC;	
	}
	
	// getter
	tm getFechaNacimiento(){return fechaNacimiento;}
	string getRaza(){return raza;}
	char getTamano(){return tamano;}
	string getTipoConcentrado(){return tipoConcentrado;}
	string getIdCliente(){return idCliente;}
	
	// setter
	void setFechaNacimiento(tm f){fechaNacimiento=f;}
	void setRaza(string r){raza=r;}
	void setTamano(char t){tamano=t;}
	void setTipoConcentrado(string c){tipoConcentrado=c;}
	void setIdCliente(string i){idCliente=i;}
};

#endif //_PERRO_H
