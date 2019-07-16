/**
 * Project Untitled
 */


#ifndef _CLIENTE_H
#define _CLIENTE_H

#include "Persona.h"
#include "../Perro.h"
#include "../Utilidades/lista.h"


class Cliente: public Persona {
private: 
    string localidad;
    Lista <Perro> perros;
public:
	Cliente(string nom, string ape, string tel, string cel, char s,string i, string tI,string lo):Persona(nom, ape, tel, cel, s, i, tI){		
		
		localidad = lo;
		perros = Lista<Perro>();
	}
	
	void addPerro(Perro perro);
	
	
	// getter
	string getLocalidad(){return localidad;}
	Lista<Perro> getPerros(){return perros;}
	
	// setter
	void setLocalidad(string l){localidad = l;}
	
	
};

 void Cliente::addPerro(Perro perro){
 	perros.insertar_nodo(perros.getTam()+1,perro);
 }
#endif //_CLIENTE_H
