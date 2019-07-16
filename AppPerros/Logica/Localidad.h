/**
 * Project Untitled
 */


#ifndef _LOCALIDAD_H
#define _LOCALIDAD_H
#include "Sucursal.h"
#include "./Persona/Paseador.h"
#include "./Persona/Cliente.h"
#include "Perro.h"
#include "./Utilidades/lista.h"

class Localidad {

private: 
    string nombre;
    int calleInicio;
    int calleFin;
    int craInicio;
    int craFin;
    Lista<Sucursal> sucursales;

public:

	Localidad(string nom, int caI, int caF, int crI, int crF){
		calleInicio = caI;
		nombre = nom;
		calleFin = caF;
		craInicio = crI;
		craFin = crF;
		sucursales = Lista<Sucursal>();				
	} 
    
	
	    
	/**
	 * Memoria Principal 3
	 */
	Lista <Paseador> getPaseadores();
	    
	/**
	 * Memoria Principal 5
	 */
	Lista <Cliente> getClientes();
	    
	/**
	 * Memoria Principal 8
	 */
	Lista<Perro> getPerros();
	
	
	
	void addSucursal(Sucursal sucursal);
	
	// getter
	string getNombre(){return nombre;}
	int getCalleIni(){return calleInicio;}
	int getCalleFin(){return calleFin;}
	int getCraIni(){return craInicio;}
	int getCraFin(){return craFin;}
	/**
	 * Memoria Principal 1
	 */
	Lista<Sucursal> getSucursales(){return sucursales;}
	
	//setter
	void getNombre(string n){nombre=n;}
	void getCalleIni(int c){calleInicio=c;}
	void getCalleFin(int c){calleFin=c;}
	void getCraIni(int c){craInicio=c;}
	void getCraFin(int c){craFin=c;}

};



/**
 * Memoria Principal 3
 * @return Lista <Paseador>
 */
Lista <Paseador> Localidad::getPaseadores() {
	
	Lista<Paseador> paseadores = Lista<Paseador>();
	for(int i=1;i<=sucursales.getTam();i++){
		for(int j=1;j<=sucursales.buscar(i).getPaseadores().getTam();j++){			
			paseadores.insertar_nodo(paseadores.getTam()+1,sucursales.buscar(i).getPaseadores().buscar(j));
		}
	}
    
    return paseadores;
}

/**
 * Memoria Principal 5
 * @return Lista <Cliente>
 */
Lista <Cliente> Localidad::getClientes() {
    Lista<Cliente> clientes = Lista<Cliente>();
	for(int i=1;i<=sucursales.getTam();i++){
		for(int j=1;j<=sucursales.buscar(i).getClientes().getTam();j++){			
			clientes.insertar_nodo(clientes.getTam()+1,sucursales.buscar(i).getClientes().buscar(j));
		}
	}
    
    return clientes;
}

/**
 * Memoria Principal 8
 * @return Lista<Perros>
 */
Lista<Perro> Localidad::getPerros() {
    Lista<Perro> perros = Lista<Perro>();
	for(int i=1;i<=sucursales.getTam();i++){
		for(int j=1;j<=sucursales.buscar(i).getPerrosSucursales().getTam();j++){			
			perros.insertar_nodo(perros.getTam()+1,sucursales.buscar(i).getPerrosSucursales().buscar(j));
		}
	}
    
    return perros;
}




#endif //_LOCALIDAD_H
