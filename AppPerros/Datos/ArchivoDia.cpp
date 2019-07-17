/**
 * Project Untitled
 */


#include "ArchivoDia.h"

/**
 * ArchivoDia implementation
 */


/**
 * @return string**
 */
string** ArchivoDia::cargarDatos() {
    ifstream Leer;
	Leer.open("dias.txt");
	Leer>>id;
	while(!Leer.eof()){
		Leer>>diaSemana;
		Leer>>horaInicio;
		Leer>>horaFin;
		printf("id %s diaSemana: %s horaInicio: %i horaFin: %i.\n", id,diaSemana,horaInicio,horaFin);
		Leer>>id;
	}
	Leer.close();
    return null;
}

/**
 * @param id
 * @param diaSemana
 * @param horaInicio
 * @param horaFin
 * @return void
 */
void ArchivoDia::guardarDatos(string id, string diaSemana, string horaInicio, string horaFin) {
    ofstream guardar;
	guardar.open("dias.txt",ios::app);
	guardar<<id<<" "<<diaSemana<<" "<<horaInicio<<" "<<horaFin<<endl;
}
