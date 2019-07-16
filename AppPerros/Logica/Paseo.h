/**
 * Project Untitled
 */


#ifndef _PASEO_H
#define _PASEO_H

class Paseo {
private: 
    String id;
    String fecha;
    String hora;
    String tipoActividad;
    RBTree<Perro,string> perrros;
    RBTree<Paseador,string> paseadores;
    /**
 * Estados posibles : (R reservado, C completado, N no cubierto)
 */
char estado;
    String localidad;
    String observaciones;
};

#endif //_PASEO_H