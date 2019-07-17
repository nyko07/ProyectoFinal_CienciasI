/**
 * Project Untitled
 */


#ifndef _PASEO_H
#define _PASEO_H

#include "./Utilidades/lista.h"
#include "./Utilidades/Date.h"
#include "./Perro.h"
#include "./Persona/Paseador.h"



#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Paseo {
private: 
    string id;
    Date fecha;
    int horaInicial;
    int horaFin;
    string tipoActividad;
    Lista<Perro> perros;
    Paseador paseador;
    /**
 * Estados posibles : (R reservado, C completado, N no cubierto)
 */
	char estado;
    string localidad;
    string observaciones;
    
public:	
	static int idActual;
	Paseo(Date f, int horI, int horF, string tipoAct, Paseador pas, string lo, string ob){
		ostringstream ss;		
		Perro::idActual++;
		ss<<idActual;
		id = ss.str();
		fecha = f;
		horaInicial = horI;
		horaFin = horF;
		tipoActividad = tipoAct;
		paseador = pas;
		localidad = lo;
		observaciones = ob;	
		estado = 'R';	
		perros = Lista<Perro>();	
	}
	
	Paseo(){
	}
	//getter
	
	Date getFecha(){return fecha;}
	int getHoraIni(){return horaInicial;}
	int getHoraFin(){return horaFin;}
	string getTipoActividad(){return tipoActividad;}
	Paseador getPaseador(){return paseador;}
	Lista<Perro> getPerros(){return perros;}
	char getEstado(){return estado;}
	string getLocalidad(){return localidad;}
	string getObservaciones(){return observaciones;}
	
	//setter
	
	void setFecha(Date f){fecha = f;}
	void setHoraIni(int h){horaInicial=h;}
	void setHoraFin(int h){horaFin=h;}
	void setTipoActividad(string d){tipoActividad=d;}
	void setPaseador(Paseador p){paseador=p;}
	
	void setEstado(char e){estado = e;}
	void setLocalidad(string d){localidad=d;}
	void setObservaciones(string d){observaciones=d;}
	
	void addPerro(Perro perro);
	
	
};

/**
 * Paseo implementation
 */
 void Paseo::addPerro(Perro perro){
 	perros.insertar_nodo(perros.getTam()+1,perro);
 }

#endif //_PASEO_H
