/**
 * Project Untitled
 */


#ifndef _PASEADOR_H
#define _PASEADOR_H

#include "Persona.h"
#include "../Dia.h"
#include "../Utilidades/lista.h"

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


class Paseador: public Persona {
private: 
    string ciudadNacimiento;
    string paisNacimiento;
    tm fechaNacimiento;
    string direccion;
    string barrio;
    Lista<Dia> dias;
public:
	Paseador(string nom, string ape, string tel, string cel, char s,string i, string tI, string ciud, string pais, tm fecha, string dir, string bar):Persona(nom, ape, tel, cel, s, i, tI){
		
		ciudadNacimiento = ciud;
		paisNacimiento = pais;
		fechaNacimiento = fecha;
		direccion = dir;
		barrio = bar;
				
	}
	
	// getter
	string getCiudadN(){return ciudadNacimiento;}
	string getPaisN(){return paisNacimiento;}
	tm getFechaN(){return fechaNacimiento;}
	string getDireccion(){return direccion;}
	string getBarrio(){return barrio;}
	
	// setter
	void setCiudadN(string c){ciudadNacimiento=c;}
	void setPaisN(string p){paisNacimiento=p;}
	void setFechaN(tm f){fechaNacimiento=f;}
	void setDireccion(string d){direccion=d;}
	void setBarrio(string b){barrio=b;}
	
	void addDia(Dia dia);
 		
	
	
	
};

void Paseador::addDia(Dia dia){
	
 	this->dias.insertar_nodo(dias.getTam()+1,dia);
}

#endif //_PASEADOR_H
