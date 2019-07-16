/**
 * Project Untitled
 */


#ifndef _PASEO_H
#define _PASEO_H

class Paseo {
private: 
    string id;
    tm fecha;
    int horaInicial;
    int horaFin;
    string tipoActividad;
    Lista<Perro> perros;
    Paseador paseador;
    /**
 * Estados posibles : (R reservado, C completado, N no cubierto)
 */
	char estado = 'R';
    string localidad;
    string observaciones;
    
public:	
	static int idActual=0;
	Paseo(tm f, int horI, int horF, string tipoAct, Paseador pas, string lo, string ob){
		idActual++;
		id = to_string(idActual);
		fecha = f;
		horaInicial = horI;
		horaFin = horF
		tipoActividad = tipoAct;
		paseador = pas;
		localidad = lo;
		observaciones = ob;			
	}
	
	//getter
	
	tm getFecha(){return fecha;}
	int getHoraIni(){return horaInicial;}
	int getHoraFin(){return horaFin;}
	int getTipoActividad(){return tipoActividad;}
	Paseador getPaseador(){return paseador;}
	Lista<Perro> getPerros(){return perros;}
	char getEstado(){return estado;}
	string getLocalidad(){return localidad;}
	string getObservaciones(){return observaciones;}
	
	//setter
	
	void setFecha(tm f){return fecha;}
	void setHoraIni(int h){horaInicial=h;}
	void setHoraFin(int h){horaFin=h;}
	void setTipoActividad(string d){tipoActividad=d;}
	void setPaseador(Paseador p){paseador=p;}
	
	void setEstado(char e){estado = e;}
	void setLocalidad(string d){localidad=d;}
	void setObservaciones(string d){observaciones=d;}
	
	void addPerro(Perro perro);
	
	
};

#endif //_PASEO_H
