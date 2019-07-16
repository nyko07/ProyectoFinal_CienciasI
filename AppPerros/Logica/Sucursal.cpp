/**
 * Project Untitled
 */


#include "Sucursal.h"
#include "./Persona/Cliente.h"
#include "Perro.h"
#include "./Utilidades/lista.h"

/**
 * Sucursal implementation
 */




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

