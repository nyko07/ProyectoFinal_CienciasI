/**
 * Project Untitled
 */


#ifndef _PASEADOR_H
#define _PASEADOR_H

#include "Persona.h"
#include "../Dia.h"
#include "../Utilidades/lista.h"
#include "../Utilidades/Date.h"


#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


class Paseador: public Persona {
private: 
    string ciudadNacimiento;
    string paisNacimiento;
    Date fechaNacimiento;
    string direccion;
    string barrio;
    Lista<Dia> dias;
public:
	//tm fecha despus de pais
	Paseador(string nom, string ape, string tel, string cel, char s,string i, string tI, Date f,string ciud, string pais, string dir, string bar):Persona(nom, ape, tel, cel, s, i, tI){
		
		ciudadNacimiento = ciud;
		paisNacimiento = pais;
		fechaNacimiento = f;
		direccion = dir;
		barrio = bar;
				
	}
	
	Paseador(){
	}
	
	// getter
	string getCiudadN(){return ciudadNacimiento;}
	string getPaisN(){return paisNacimiento;}
	Date getFechaN(){return fechaNacimiento;}
	string getDireccion(){return direccion;}
	string getBarrio(){return barrio;}
	
	// setter
	void setCiudadN(string c){ciudadNacimiento=c;}
	void setPaisN(string p){paisNacimiento=p;}
	void setFechaN(Date f){fechaNacimiento=f;}
	void setDireccion(string d){direccion=d;}
	void setBarrio(string b){barrio=b;}
	
	void addDia(Dia dia);
 		
	
	
	
};

void Paseador::addDia(Dia dia){
	
 	this->dias.insertar_nodo(dias.getTam()+1,dia);
}

#endif //_PASEADOR_H
