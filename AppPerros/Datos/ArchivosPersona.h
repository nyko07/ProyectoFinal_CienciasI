/**
 * Project Untitled
 */


#ifndef _ARCHIVOSPERSONA_H
#define _ARCHIVOSPERSONA_H

#include "../Logica/Utilidades/lista.h"
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
	Lista < Lista<string> > cargarDatos();
	void guardarDatos(string id, string nombre, string apellido,string telefono,string celular, char sexo, string email);
	Lista<string> separarTextos(char separador, string texto);
	  
};
Lista< Lista<string> > ArchivosPersona::cargarDatos() {
    ifstream Leer;
	Leer.open("registros/Localidades.txt");
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
Lista<string> ArchivosPersona::separarTextos(char separador, string texto){
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
 * @param nombre
 * @param apellido
 * @param sexo
 * @param email
 * @param telefono
 * @return void
 */
void ArchivosPersona::guardarDatos(string id, string nombre, string apellido,string telefono,string celular, char sexo, string email) {
    ofstream guardar;
	guardar.open("registros/Localidades.txt",ios::app);
	guardar<<id<<" "<<nombre<<" "<<apellido<<" "<<telefono<<" "<<celular<<" "<<sexo<<" "<<email<<endl;
}
#endif //_ARCHIVOSPERSONA_H
