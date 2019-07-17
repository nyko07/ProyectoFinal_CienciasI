/**
 * Project Untitled
 */

#ifndef _PERRO_H
#define _PERRO_H

#include "./Utilidades/Date.h"
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Perro {
private: 
    string id;
    Date fechaNacimiento;
    string nombre;
    string raza;
    char tamano;
    string tipoConcentrado;
    string idCliente;
public:
	
	//tm f
	Perro(string n,Date f,string r ,char tam, string tipoC, string iC){		
		nombre = n;
		ostringstream ss;		
		idActual++;
		ss<<idActual;
		id = ss.str();		
		fechaNacimiento = f;
		raza = r;	
		tamano = tam;
		tipoConcentrado = tipoC;
		idCliente = iC;	
	}
	
	Perro(){		
		
	}
	
	// getter
	Date getFechaNacimiento(){return fechaNacimiento;}
	string getRaza(){return raza;}
	string getNombre(){return nombre;}
	char getTamano(){return tamano;}
	string getTipoConcentrado(){return tipoConcentrado;}
	string getIdCliente(){return idCliente;}
	string getId(){return id;}
	
	// setter
	void setFechaNacimiento(Date f){fechaNacimiento=f;}
	void setRaza(string r){raza=r;}
	void setTamano(char t){tamano=t;}
	void setNombre(string t){nombre=t;}
	void setTipoConcentrado(string c){tipoConcentrado=c;}
	void setIdCliente(string i){idCliente=i;}	

	
	static int idActual;
};


//Perro::idActual = 0;

#endif //_PERRO_H
