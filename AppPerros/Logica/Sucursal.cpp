/**
 * Project Untitled
 */


#include "Sucursal.h"
#include "../Persona/Cliente.h"
#include "Perro.h"
#include "../Utilidades/lista.h"

/**
 * Sucursal implementation
 */




/**
 * Memoria Principal 7
 * @return Lista <Perros>
 */
Lista <Perros> Sucursal::getPerrosSucursales() {
	Lista<Perro> perros = Lista<Perro>();
	for(int i=1;i<=clientes.getTam();i++){
		for(int j=1;j<=clientes.buscar(i).getPerros().getTam();j++){			
			clientes.insertar_nodo(perros.getTam()+1,clientes.buscar(i).getPerros().buscar(j));
		}
	}    
    return perros;
}

