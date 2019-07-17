/**
 * Project Untitled
 */


#ifndef _ARCHIVOSSUCURSALES_H
#define _ARCHIVOSSUCURSALES_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;

class ArchivosSucursales: public Archivos {
/**
 * @param id
 * @param nombre
 * @param gerente
 * @param idLocalidad
 */	
private: 
    string id;
    string nombre;
    string gerente;
    string idLocalidad;
    
public:
	int getTam();
	string ** cargarDatos();
   	void guardarDatos(string id, string nombre, string gerente, string idLocalidad); 
};

int ArchivosSucursales::getTam(){
	FILE*f;
	char temp[50];
	int n;
	f = fopen("perros.txt","r");
	
	if(f==NULL){
		printf("No se abrio el archivo");
	}
	while(!feof(f)){
		fgets(temp,50,f);
		n++;
	}
	rewind(f);
	return n-1;
}

string** ArchivosSucursales::cargarDatos() {
    ifstream Leer;
	Leer.open("sucursales.txt");
	Leer>>id;
	while(!Leer.eof()){
		Leer>>nombre;
		Leer>>gerente;
		Leer>>idLocalidad;	
		Leer>>id;
	}
	Leer.close();
    return NULL;
}

/**
 * @param id
 * @param nombre
 * @param gerente
 * @param idLocalidad
 * @return void
 */
void ArchivosSucursales::guardarDatos(string id, string nombre, string gerente, string idLocalidad) {
    ofstream guardar;
	guardar.open("Localidades.txt",ios::app);
	guardar<<id<<" "<<nombre<<" "<<gerente<<" "<<idLocalidad<<endl;
}

#endif //_ARCHIVOSSUCURSALES_H
