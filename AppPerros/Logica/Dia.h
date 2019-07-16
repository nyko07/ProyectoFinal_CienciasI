/**
 * Project Untitled
 */


#ifndef _DIA_H
#define _DIA_H

using namespace std;

class Dia {
private: 	
    string id;
    string diaSemana;
    int horaInicio;
    int horaFin;
    
public:
	static int idActual = 0;
	Dia(string diaS, int hIni, int hFin){
		idActual++;
		id=to_string(idActual);
		horaInicio = hIni;
		horaFin = hFin;		
	}
	
	//getter
	string getId(){return id;}
	string getDiaSemana(){return diaSemana;}
	string getHoraIni(){return horaInicio;}
	string getHoraFin(){return horaFin;}
	
	//setter	
	void setDiaSemana(string d){diaSemana=d;}
	void setHoraIni(string h){horaInicio=h;}
	void setHoraFin(string h){horaFin=h;}
	
};

#endif //_DIA_H
