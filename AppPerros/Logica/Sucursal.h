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
	 * Memoria Principal 6
	 * @param n
	 */
	Lista <Clientes> clienteMasPerros(int n);
	    
	/**
	 * Memoria Principal 7
	 */
	Lista <Perros> getPerrosSucursales();
	    
	/**
	 * Memoria Principal 9
	 * @param n
	 */
	void getPerrosCumple(int  n);
	
	//getter
	string getId(){return id;}
	string getNombre(){return nombre;}
	string getGerente(){return gerente;}
	/**
	 * Memoria Principal 2
	 */
	Lista <Paseadores> getPaseadores();
	    
	/**
	 * Memoria Principal 4
	 */
	Lista <Clientes> getClientes();
	
	// setter	
	string setNombre(string n){nombre=n;}
	string setGerente(string g){gerente=g;}
	
	void addPaseador(Paseador p);
	void addCliente(Cliente c);
	
	

};

#endif //_SUCURSAL_H
