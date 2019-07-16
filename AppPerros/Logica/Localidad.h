/**
 * Project Untitled
 */


#ifndef _LOCALIDAD_H
#define _LOCALIDAD_H
#include "Sucursal.h"
#include "../Persona/Paseador.h"
#include "../Persona/Cliente.h"
#include "Perro.h"
#include "../Utilidades/lista.h"

class Localidad {

private: 
    string nombre;
    int calleInicio;
    int calleFin;
    int craInicio;
    int craFin;
    Lista<Sucursal> sucursales;

public: 
    
	
	    
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
	Lista<Perros> getPerros();
	
	
	
	void addSucursal(Sucursal sucursal);
	
	// getter
	string getNombre(){return nombre;}
	int getCalleIni(){return calleInicio;}
	int getCalleFin(){return calleFin;}
	int getNumPaseadores(){return numeroPaseadores;}
	int getCraIni(){return craInicio;}
	int getCraFin(){return craFin;}
	/**
	 * Memoria Principal 1
	 */
	Lista<Sucursal> getSucursales(){return sucursales};
	
	//setter
	void getNombre(string n){nombre=n;}
	void getCalleIni(int c){calleInicio=c;}
	void getCalleFin(int c){calleFin=c;}
	void getCraIni(int c{craInicio=c;}
	void getCraFin(int c){craFin=c;}

};




#endif //_LOCALIDAD_H
