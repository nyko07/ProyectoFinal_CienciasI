/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPASEADORES_H
#define _ARCHIVOSPASEADORES_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;


class ArchivosPaseadores: public Archivos { 
/**
 * @param id
 * @param ciudadNacimiento
 * @param paisNacimiento
 * @param fechaNacimiento
 * @param direccion
 * @param barrio
 */

private: 
    string nombre;
    string ciudadNacimiento;
    string paisNacimiento;
    string fechaNacimiento;
    string direccion;
    string barrio;
    string idSucursal;
public:
	string** cargarDatos();
	void guardarDatos(string nombre, string idSucursal, string paisNacimiento, string barrio, string ciudadNacimiento, string direccion, string fechaNacimiento);	    
};

string** ArchivosPaseadores::cargarDatos() {
    ifstream Leer;
	Leer.open("paseadores.txt");
	Leer>>nombre;
	while(!Leer.eof()){
		Leer>>idSucursal;
		Leer>>paisNacimiento;
		Leer>>barrio;
		Leer>>ciudadNacimiento;
		Leer>>direccion;
		Leer>>fechaNacimiento;
		
		Leer>>nombre;
	}
	Leer.close();	
	
    return NULL;
}

/**
 * @param id
 * @param ciudadNacimiento
 * @param paisNacimiento
 * @param fechaNacimiento
 * @param direccion
 * @param barrio
 * @return void
 */
void ArchivosPaseadores::guardarDatos(string nombre, string idSucursal, string paisNacimiento, string barrio, string ciudadNacimiento, string direccion, string fechaNacimiento) {
    ofstream guardar;
	guardar.open("paseadores.txt",ios::app);
	guardar<<nombre<<" "<<idSucursal<<" "<<paisNacimiento<<" "<<barrio<<" "<<ciudadNacimiento<<" "<<direccion<<" "<<fechaNacimiento<<endl;
}

#endif //_ARCHIVOSPASEADORES_H
