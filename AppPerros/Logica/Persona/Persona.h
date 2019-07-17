/**
 * Project Untitled
 */


#ifndef _PERSONA_H
#define _PERSONA_H

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Persona{
private: 
    string id;
    string nombre;
    string apellido;    
    string telefono;
    string celular;
    char sexo;
    string email;
public:
	Persona(string nom, string ape, string tel, string cel, char s,string i, string tI, string e){
		email = e;
		nombre = nom;
		apellido = ape;
		telefono = tel;
		celular = cel;
		sexo = s;
		id = i+" "+tI;		
	}
	Persona(){
	}
	// getter
	string getId(){return id;}
	string getNombre(){return nombre;}
	string getApellido(){return apellido;}
	string getTelefono(){return telefono;}
	string getCelular(){return celular;}
	char getSexo(){return sexo;}
	string getEmail(){return email;}
	
	// setter
	void setId(string i){id = i;}
	void setNombre(string n){nombre = n;}
	void setApellido(string a){apellido = a;}
	void setTelefono(string t){telefono = t;}
	void setCelular(string c){celular = c;}
	void setSexo(char s){sexo = s;}
	void setEmail(string e){email = e;}
};

#endif //_PERSONA_H
