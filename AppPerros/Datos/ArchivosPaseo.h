/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPASEO_H
#define _ARCHIVOSPASEO_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;


class ArchivosPaseo: public Archivos {
    
/**
 * @param idPaseador
 * @param idPerro
 * @param observaciones
 * @param tipoActividades
 * @param fecha
 * @param hora
 * @param duracion
 */

private:
	string id; 
    string idPaseador;
    string idPerro;
    string observaciones;
    string tipoActividades;
    string fecha;
    string hora;
    string duracion;
public:
	string** cargarDatos();
	void  guardarDatos(string id, string idPaseador, string idPerro, string observaciones, string tipoActividades, string fecha, string hora, string duracion);
};

string** ArchivosPaseo::cargarDatos() {
	ifstream Leer;
	Leer.open("paseo.txt");
	Leer>>id;
	while(!Leer.eof()){
		Leer>>idPaseador;
		Leer>>idPerro;
		Leer>>observaciones;
		Leer>>tipoActividades;
		Leer>>fecha;
		Leer>>hora;
		Leer>>duracion;
		
		Leer>>id;
	}
	Leer.close();		
    return NULL;
}

/**
 * @param idPaseador
 * @param idPerro
 * @param observaciones
 * @param tipoActividades
 * @param fecha
 * @param hora
 * @param duracion
 * @return void
 */
void ArchivosPaseo::guardarDatos(string id,string idPaseador, string idPerro, string observaciones, string tipoActividades, string fecha, string hora, string duracion) {
    ofstream guardar;
	guardar.open("paseo.txt",ios::app);
	guardar<<id<<" "<<idPaseador<<" "<<idPerro<<" "<<observaciones<<" "<<tipoActividades<<" "<<fecha<<" "<<hora<<" "<<duracion<<endl;
}

#endif //_ARCHIVOSPASEO_H
