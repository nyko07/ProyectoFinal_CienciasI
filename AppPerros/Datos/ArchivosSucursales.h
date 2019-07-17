/**
 * Project Untitled
 */


#ifndef _ARCHIVOSSUCURSALES_H
#define _ARCHIVOSSUCURSALES_H

#include "../Logica/Utilidades/lista.h"
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
	
   	void guardarDatos(string id, string nombre, string gerente, string idLocalidad); 
   	Lista< Lista<string> > cargarDatos();
   	Lista<string> separarTextos(char separador, string texto);
};


Lista< Lista<string> > ArchivosSucursales::cargarDatos() {
    ifstream Leer;
	Leer.open("registros/Sucursales.txt");
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
Lista<string> ArchivosSucursales::separarTextos(char separador, string texto){
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
 * @param gerente
 * @param idLocalidad
 * @return void
 */
void ArchivosSucursales::guardarDatos(string id, string nombre, string gerente, string idLocalidad) {
    ofstream guardar;
	guardar.open("Sucursales.txt",ios::app);
	guardar<<id<<" "<<nombre<<" "<<gerente<<" "<<idLocalidad<<endl;
}

#endif //_ARCHIVOSSUCURSALES_H
