/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPERROS_H
#define _ARCHIVOSPERROS_H

#include "Archivos.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;




class ArchivosPerros: public Archivos {
/**
 * @param id
 * @param idCliente
 * @param fechaNacimiento
 * @param raza
 * @param tamanio
 * @param tipoConcentrado
 */
private: 
    string id;
    string idCliente;
    string fechaNacimiento;
    string raza;
    char tamanio;
    string tipoConcentrado;
    
public:
	int getTam();
	string ** cargarDatos();
   	void guardarDatos(string id, string idCliente, string fechaNacimiento, string raza, char tamanio, string tipoConcentrado); 
};

int ArchivosPerros::getTam(){
	FILE*f;
	char temp[50];
	int n;
	f = fopen("registros/perros.txt","r");
	
	if(f==NULL){
		printf("No se abrio el archivo");
	}
	while(!feof(f)){
		fgets(temp,50,f);
		n++;
	}
	rewind(f);
	return n;
}
/**
 * @return string**
 */
string ** ArchivosPerros::cargarDatos() {
	cout<<"entra";
    ifstream Leer;
	Leer.open("registros/perros.txt");
	int x = getTam();
	string **tmp = new string*[10];
	int a = 0;
	int b = 0;
	
	Leer>>id;
	while(!Leer.eof()){
		cout<<b;
		tmp[a][b] = id;
		b++;
		cout<<b;

		Leer>>idCliente;
		tmp[a][b] = idCliente;
		b++;
		cout<<b;
		Leer>>fechaNacimiento;
		tmp[a][b] = fechaNacimiento;
		b++;
		cout<<b;
		Leer>>raza;
		tmp[a][b] = raza;
		b++;
		cout<<b;
		Leer>>tamanio;
		tmp[a][b] = tamanio;
		b++;
		cout<<b;
		Leer>>tipoConcentrado;
		tmp[a][b] = tipoConcentrado;
		b++;
		
		b = 0;
		a++;
		Leer>>id;
	}
	Leer.close();
    return tmp;
}

/**
 * @param id
 * @param idCliente
 * @param fechaNacimiento
 * @param raza
 * @param tamanio
 * @param tipoConcentrado
 * @return void
 */
void ArchivosPerros::guardarDatos(string id, string idCliente, string fechaNacimiento, string raza, char tamanio, string tipoConcentrado) {
    ofstream guardar;
	guardar.open("registros/perros.txt",ios::app);
	guardar<<id<<" "<<idCliente<<" "<<fechaNacimiento<<" "<<raza<<" "<<tamanio<<" "<<tipoConcentrado<<endl;
}

#endif //_ARCHIVOSPERROS_H
