/**
 * Project Untitled
 */


#ifndef _PERRO_H
#define _PERRO_H

class Perro {
private: 
    String id;
    tm fechaNacimiento;
    String raza;
    char tamano;
    String tipoConcentrado;
    string idCliente;
public:
	static int idActual=0;
	Perro(tm f, string r, char tam, string tipoC, string iC){
		idActual++;
		id = to_string(idActual);
		fechaNacimiento = f;
		raza = r;	
		tamano = tam;
		tipoConcentrado = tipoC;
		idCliente = iC;	
	}
	
	// getter
	tm getFechaNacimiento(){return fechaNacimiento;}
	string getRaza(){return raza;}
	char getTamano(){return tamano;}
	string getTipoConcentrado(){return tipoConcentrado;}
	string getIdCliente(){return idCliente;}
	
	// setter
	void setFechaNacimiento(tm f){fechaNacimiento=f;}
	void setRaza(string r){raza=r;}
	void setTamano(char t){tamano=t;}
	void setTipoConcentrado(string c){tipoConcentrado=c;}
	void setIdCliente(string i){idCliente=i;}
};

#endif //_PERRO_H
