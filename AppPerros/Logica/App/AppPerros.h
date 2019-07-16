/**
 * Project Untitled
 */


#ifndef _APPPERROS_H
#define _APPPERROS_H

#include "../Utilidades/lista.h"
#include "../Persona/Cliente.h"
#include "../Persona/Paseador.h"
#include "../Paseo.h"
#include "../Perro.h"
#include "./Simulacion.h"

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


class AppPerros {
	
	

private: 
    Simulacion simulacion;
    Archivos  archivos;
    RBTree <Localidad,id> localidades;
    Lista <Paseo> paseos;
    RBTree <Cliente,int> clientes;
    RBTree <Sucursal, int> sucursales;
    RBTree <Paseador, int> paseadores;
    RBTree <Perro, int> perros;
    
public:
	AppPerros(){
		paseos = Lista<Paseo>();
	}
	
	/**
	 * Memoria Principal 6
	 * @param n
	 */
	Lista <Cliente> clienteMasPerros(int n);
	
	/**
		 * Memoria Principal 9
		 * @param n
		 */
	void getPerrosCumple(int  n);  
/**
	 * Consultas 1
	 * @param clIni
	 * @param clFin
	 * @param crIni
	 * @param crFin
	 */
	Lista <Sucursal> getAreaSucursales(int clIni, int clFin, int crIni, int crFin);
	    
	/**
	 * Consultas 2
	 * @param dia
	 */
	Lista <Paseador> getPaseadoresDisponibles(Dia dia);
	    
	/**
	 * Consultas 4
	 * @param localidad
	 * @param raza
	 */
	Lista <Cliente> getPerrosRaza(String  localidad, String  raza);
	    
	/**
	 * Consultas 5
	 * @param tm hIni
	 * @param tm hFin
	 */
	Lista <Paseo> getDatosPerroPaseo(void tm hIni, void tm hFin);
	    
	/**
	 * Consultas 6
	 * @param idPerro
	 */
	Lista <Paseo> getPaseadores(String  idPerro);
	    
	/**
	 * Consultas 7
	 * @param localidad
	 * @param tam
	 */
	Lista <Perro> getPerrosTam(String  localidad, char  tam);
	    
	/**
	 * Consultas 3
	 * @param cliente
	 * @param dia
	 */
	Lista <Paseador> getPaseadoresDisponibles(Cliente cliente, Dia dia);
	    
	/**
	 * Consultas 8
	 * @param rangoIni
	 * @param rangoFin
	 */
	void getPerrosEdad(tm rangoIni, tm rangoFin);
	    
	/**
	 * @param cliente
	 * @param perro
	 * @param horario
	 */
	bool reservar(Cliente cliente, Perro perro, Dia horario);
};

#endif //_APPPERROS_H
