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

/**
 * Memoria Principal 7
 * @return Lista <Perros>
 */
Lista <Perro> Sucursal::getPerrosSucursales() {
	Lista<Perro> perros = Lista<Perro>();
	for(int i=1;i<=clientes.getTam();i++){
		for(int j=1;j<=clientes.buscar(i).getPerros().getTam();j++){			
			perros.insertar_nodo(perros.getTam()+1,clientes.buscar(i).getPerros().buscar(j));
		}
	}    
    return perros;
}

void Sucursal::addCliente(Cliente c){
	clientes.insertar_nodo(clientes.getTam()+1,c);
}

void Sucursal::addPaseador(Paseador c){
	paseadores.insertar_nodo(paseadores.getTam()+1,c);
}

#endif //_SUCURSAL_H
