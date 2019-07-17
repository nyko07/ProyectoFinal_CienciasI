/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPERROS_H
#define _ARCHIVOSPERROS_H

#include "../Logica/Utilidades/lista.h"
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
   	void guardarDatos(string id, string idCliente, string fechaNacimiento, string raza, char tamanio, string tipoConcentrado); 
	Lista<string> separarTextos(char separador, string texto);
	Lista< Lista<string> > cargarDatos();
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
Lista< Lista<string> > ArchivosPerros::cargarDatos() {
	//cout<<"entra";
    ifstream Leer;
	Leer.open("registros/perros.txt");
	int x = getTam();
	//string *tmp = new string[10];
	int a = 0;
	
	
	string linea;
	
	
	
	Lista< Lista<string> > l;
	while(getline(Leer,linea)){
		Lista<string> lista= separarTextos(' ',linea);
		Lista<string> aux;
		for(int i=1;i<=lista.getTam();i++){
			aux.insertar_nodo(aux.getTam()+1,lista.buscar(i));						
			//cout<<tmp[a][i]<<"hola"<<endl;
		}
		l.insertar_nodo(l.getTam()+1,aux);		
		
		
		
		a++;
		
		
	}
	
	Leer.close();
    return l;
}

Lista<string> ArchivosPerros::separarTextos(char separador, string texto){
	Lista<string> lista;
	int in=0;
	int fi=0;
	string palabra;
	for(int i=0;i<texto.length();i++){
		
		if(texto[i]==separador){
			fi=i+1;
			palabra = "";
			for(int j=in;j<fi;j++){
				palabra = palabra + texto[j];
			}
			
			lista.insertar_nodo(lista.getTam()+1,palabra);
			
			in=fi;
		}
	}
	palabra = "";
	fi=texto.length();
	for(int j=in;j<fi;j++){
				palabra = palabra + texto[j];
	}
	
	lista.insertar_nodo(lista.getTam()+1,palabra);
	
	return lista;
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
