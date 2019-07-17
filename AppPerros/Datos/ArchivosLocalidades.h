/**
 * Project Untitled
 */


#ifndef _ARCHIVOSLOCALIDADES_H
#define _ARCHIVOSLOCALIDADES_H

#include "../Logica/Utilidades/lista.h"
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
	Lista< Lista<string> > cargarDatos();
   	Lista<string> separarTextos(char separador, string texto);
	void guardarDatos(string nombre, int calleInicio, int calleFin, int numeroPaseadores, int craInicio, int craFin);
};
Lista< Lista<string> > ArchivosLocalidades::cargarDatos() {
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
Lista<string> ArchivosLocalidades::separarTextos(char separador, string texto){
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
	guardar.open("registros/Localidades.txt",ios::app);
	guardar<<nombre<<" "<<calleInicio<<" "<<calleFin<<" "<<numeroPaseadores<<" "<<craInicio<<" "<<craFin<<endl;
}

#endif //_ARCHIVOSLOCALIDADES_H
