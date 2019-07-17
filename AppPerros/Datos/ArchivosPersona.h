/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPERSONA_H
#define _ARCHIVOSPERSONA_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;


class ArchivosPersona: public Archivos {
/**
 * @param id
 * @param nombre
 * @param apellido
 * @param sexo
 * @param email
 * @param telefono
 */

private: 
    string id;
    string nombre;
    string apellido;
    char sexo;
    string email;
    string telefono;
    string celular;
public:
	string** cargarDatos();
	void guardarDatos(string id, string nombre, string apellido,string telefono,string celular, char sexo, string email);
	  
};
string** ArchivosPersona::cargarDatos() {
    ifstream Leer;
	Leer.open("personas.txt");
	Leer>>id;
	while(!Leer.eof()){
		Leer>>nombre;
		Leer>>apellido;
		Leer>>telefono;
		Leer>>celular;
		Leer>>sexo;
		Leer>>email;
		Leer>>id;
	}
	Leer.close();
    return NULL;
}

/**
 * @param id
 * @param nombre
 * @param apellido
 * @param sexo
 * @param email
 * @param telefono
 * @return void
 */
void ArchivosPersona::guardarDatos(string id, string nombre, string apellido,string telefono,string celular, char sexo, string email) {
    ofstream guardar;
	guardar.open("Localidades.txt",ios::app);
	guardar<<id<<" "<<nombre<<" "<<apellido<<" "<<telefono<<" "<<celular<<" "<<sexo<<" "<<email<<endl;
}
#endif //_ARCHIVOSPERSONA_H
