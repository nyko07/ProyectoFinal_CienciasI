/**
 * Project Untitled
 */


#ifndef _SUCURSAL_H
#define _SUCURSAL_H

#include "../Persona/Paseador.h"
#include "../Persona/Cliente.h"
#include "Perro.h"
#include "../Utilidades/lista.h"


using namespace std;

class Sucursal {

private: 
    String id;
    String nombre;
    String gerente;
    Lista<Paseador> paseadores;
    Lista<Cliente> clientes;    

public:     
	static int idActual=0;
	Sucursal(string nom, string gere){
		idActual++;
		id = to_string(idActual);
		nombre = nom;
		gerente = gere;		
	}	    
	
	    
	/**
	 * Memoria Principal 7
	 */
	Lista <Perros> getPerrosSucursales();
	    
	
	
	//getter
	string getId(){return id;}
	string getNombre(){return nombre;}
	string getGerente(){return gerente;}
	/**
	 * Memoria Principal 2
	 */
	Lista <Paseadores> getPaseadores(){return paseadores;}
	    
	/**
	 * Memoria Principal 4
	 */
	Lista <Clientes> getClientes(){return clientes;}
	
	// setter	
	string setNombre(string n){nombre=n;}
	string setGerente(string g){gerente=g;}
	
	void addPaseador(Paseador p);
	void addCliente(Cliente c);
	
	

};

#endif //_SUCURSAL_H
