/**
 * Project Untitled
 */


#ifndef _DIA_H
#define _DIA_H

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Dia {
private: 	
    string id;
    string diaSemana;
    int horaInicio;
    int horaFin;
    
public:
	static int idActual;
	Dia(string diaS, int hIni, int hFin){
		ostringstream ss;		
		idActual++;
		//ss<<idActual;
		//id = ss.str();
		horaInicio = hIni;
		horaFin = hFin;		
	}
	Dia(){
	}
	
	//getter
	string getId(){return id;}
	string getDiaSemana(){return diaSemana;}
	int getHoraIni(){return horaInicio;}
	int getHoraFin(){return horaFin;}
	
	//setter	
	void setDiaSemana(string d){diaSemana=d;}
	void setHoraIni(int h){horaInicio=h;}
	void setHoraFin(int h){horaFin=h;}
	
};

#endif //_DIA_H
