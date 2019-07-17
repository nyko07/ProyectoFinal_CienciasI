#ifndef DATE_H
#define DATE_H

#include <ctime>

#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


class Date{
	private:				
		tm * fecha;
		string semana[7] = { "Domingo", "Lunes", "Martes", "Miercoles","Jueves", "Viernes", "Sabado"};
        string meses[12] = { "Enero", "Febrero","Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre","Diciembre"};
	public: 
	
		Date(int d, int m, int a){
			fecha->tm_mday = d;
			fecha->tm_mon = m-1;
			fecha->tm_year = a-1900;
			
			mktime(fecha);
		}	
		
		Date(){
			time_t rawtime;
			time(&rawtime);
			fecha = localtime(&rawtime);
		}
		
		int getDia(){return fecha->tm_mday;}
		int getMes(){return fecha->tm_mon;}	
		int getAnio(){return fecha->tm_year;}
		
		string getDiaSemana(){return semana[fecha->tm_wday];}
		string getMesT(){return meses[fecha->tm_mon];}		
		
	
};






#endif
