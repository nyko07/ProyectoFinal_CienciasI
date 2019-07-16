/**
 * Project Untitled
 */


#ifndef _SUCURSAL_H
#define _SUCURSAL_H

#include "./Persona/Paseador.h"
#include "./Persona/Cliente.h"
#include "Perro.h"
#include "./Utilidades/lista.h"

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

class Sucursal {

private: 
    string id;
    string nombre;
    string gerente;
    Lista<Paseador> paseadores;
    Lista<Cliente> clientes;    

public:     
	static int idActual;
	Sucursal(string nom, string gere){
		ostringstream ss;		
		Perro::idActual++;
		ss<<idActual;
		id = ss.str();
		nombre = nom;
		gerente = gere;		
	}	    
	
	    
	/**
	 * Memoria Principal 7
	 */
	Lista <Perro> getPerrosSucursales();
	    
	
	
	//getter
	string getId(){return id;}
	string getNombre(){return nombre;}
	string getGerente(){return gerente;}
	/**
	 * Memoria Principal 2
	 */
	Lista <Paseador> getPaseadores(){return paseadores;}
	    
	/**
	 * Memoria Principal 4
	 */
	Lista <Cliente> getClientes(){return clientes;}
	
	// setter	
	string setNombre(string n){nombre=n;}
	string setGerente(string g){gerente=g;}
	
	void addPaseador(Paseador p);
	void addCliente(Cliente c);
	
	

};

#endif //_SUCURSAL_H
