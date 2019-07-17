/**
 * Project Untitled
 */


#ifndef _ARCHIVODIA_H
#define _ARCHIVODIA_H

#include "Archivos.h"


class ArchivoDia: public Archivos {
public: 
    
string** cargarDatos();
    
/**
 * @param id
 * @param diaSemana
 * @param horaInicio
 * @param horaFin
 */
void guardarDatos(string id, string diaSemana, string horaInicio, string horaFin);
private: 
    string id;
    string diaSemana;
    string horaInicio;
    string horaFin;
};

#endif //_ARCHIVODIA_H