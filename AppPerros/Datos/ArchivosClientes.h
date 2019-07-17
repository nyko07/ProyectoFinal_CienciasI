/**
 * Project Untitled
 */


#ifndef _ARCHIVOSCLIENTES_H
#define _ARCHIVOSCLIENTES_H

#include "../Logica/Utilidades/lista.h"
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
	Lista< Lista<string> > cargarDatos();
   	Lista<string> separarTextos(char separador, string texto);
	void guardarDatos(string nombre, string nombreSucursal, string idLocalidad);
	
};
Lista< Lista<string> > ArchivosClientes::cargarDatos() {
    ifstream Leer;
	Leer.open("registros/cliente.txt");
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
Lista<string> ArchivosClientes::separarTextos(char separador, string texto){
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
 * @param nombreSucursal
 * @param idLocalidad
 * @return void
 */
void ArchivosClientes::guardarDatos(string nombre, string nombreSucursal, string idLocalidad) {
    ofstream guardar;
	guardar.open("registros/cliente.txt",ios::app);
	guardar<<nombre<<" "<<nombreSucursal<<" "<<idLocalidad<<endl;
}

#endif //_ARCHIVOSCLIENTES_H
