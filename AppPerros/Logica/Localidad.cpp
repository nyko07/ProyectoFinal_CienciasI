/**
 * Project Untitled
 */


#include "Localidad.h"
#include "../Persona/Paseador.h"
#include "../Persona/Cliente.h"
#include "Perro.h"
#include "../Utilidades/lista.h"

/**
 * Localidad implementation
 */


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
Lista<Perros> Localidad::getPerros() {
    Lista<Perro> perros = Lista<Perro>();
	for(int i=1;i<=sucursales.getTam();i++){
		for(int j=1;j<=sucursales.buscar(i).getPerrosSucursales().getTam();j++){			
			perros.insertar_nodo(perros.getTam()+1,sucursales.buscar(i).getPerrosSucursales().buscar(j));
		}
	}
    
    return perros;
}
