/**
 * Project Untitled
 */


#ifndef _ARCHIVOSCLIENTES_H
#define _ARCHIVOSCLIENTES_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;


class ArchivosClientes: public Archivos {
 
/**
 * @param id
 * @param nombreSucursal
 * @param idLocalidad
 */
 
private: 
    string nombre;
    string nombreSucursal;
    string idLocalidad;
public:
	string** cargarDatos();
	void guardarDatos(string nombre, string nombreSucursal, string idLocalidad);
	
};
string** ArchivosClientes::cargarDatos() {
    ifstream Leer;
	Leer.open("clientes.txt");
	Leer>>nombre;
	while(!Leer.eof()){
		Leer>>nombreSucursal;
		Leer>>idLocalidad;
		Leer>>nombre;
	}
	Leer.close();
    return NULL;
}

/**
 * @param id
 * @param nombreSucursal
 * @param idLocalidad
 * @return void
 */
void ArchivosClientes::guardarDatos(string nombre, string nombreSucursal, string idLocalidad) {
    ofstream guardar;
	guardar.open("clientes.txt",ios::app);
	guardar<<nombre<<" "<<nombreSucursal<<" "<<idLocalidad<<endl;
}

#endif //_ARCHIVOSCLIENTES_H
