/**
 * Project Untitled
 */


#ifndef _ARCHIVOSLOCALIDADES_H
#define _ARCHIVOSLOCALIDADES_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;


class ArchivosLocalidades: public Archivos {
    
/**
 * @param nombre
 * @param calleInicio
 * @param calleFin
 * @param numeroPaseadores
 * @param craInicio
 * @param craFin
 */
private: 
    string nombre;
    string calleInicio;
    string calleFin;
    string numeroPaseadores;
    string craInicio;
    string craFin;
public:
	string** cargarDatos();
	void guardarDatos(string nombre, int calleInicio, int calleFin, int numeroPaseadores, int craInicio, int craFin);
};
string** ArchivosLocalidades::cargarDatos() {
   ifstream Leer;
	Leer.open("Localidades.txt");
	Leer>>nombre;
	while(!Leer.eof()){
		Leer>>calInicio;
		Leer>>calFin;
		Leer>>numeroPaseadores;
		Leer>>craInicio;
		Leer>>craFin;
		
		Leer>>nombre;
	}
	Leer.close();
    return NULL;
}

/**
 * @param nombre
 * @param calleInicio
 * @param calleFin
 * @param numeroPaseadores
 * @param craInicio
 * @param craFin
 * @return void
 */
void ArchivosLocalidades::guardarDatos(string nombre, int calleInicio, int calleFin, int numeroPaseadores, int craInicio, int craFin) {
    ofstream guardar;
	guardar.open("Localidades.txt",ios::app);
	guardar<<nombre<<" "<<calInicio<<" "<<calFin<<" "<<numeroPaseadores<<" "<<craInicio<<" "<<craFin<<endl;
}

#endif //_ARCHIVOSLOCALIDADES_H
