/**
 * Project Untitled
 */


#ifndef _PASEADOR_H
#define _PASEADOR_H

#include "Persona.h"
#include "../Dia.h"


class Paseador: public Persona {
private: 
    string ciudadNacimiento;
    string paisNacimiento;
    tm fechaNacimiento;
    string direccion;
    string barrio;
    Lista<Dia> dias;
public:
	Paseador(string nom, string ape, string tel, string cel, char s,string i, string tI, string ciud, string pais, tm fecha, string dir, string bar){
		this->Persona(nom, ape, tel, cel, s, i, tI);
		ciudadNacimiento = ciud;
		paisNacimiento = pais;
		fechaNacimiento = fecha;
		direccion = dir;
		barrio = bar;
		Lista<Dia> dias = Lista<Dia>();		
	}
	
	// getter
	string getCiudadN(){return ciudadNacimiento;}
	string getPaisN(){return paisNacimiento;}
	tm getFechaN(){return fechaNacimiento;}
	string getDireccion(){return direccion;}
	string getBarrio(){return barrio;}
	
	// setter
	void setCiudadN(string c){ciudadNacimiento=c;}
	void setPaisN(string p){return paisNacimiento=p;}
	void setFechaN(tm f){return fechaNacimiento=f;}
	void setDireccion(string d){return direccion=d;}
	void setBarrio(string b){return barrio=b;}
	
	void addDia(Dia dia);	
	
	
	
};

#endif //_PASEADOR_H
