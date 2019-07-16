/**
 * Project Untitled
 */


#ifndef _SIMULACION_H
#define _SIMULACION_H

class Simulacion {
public: 
    
/**
 * @param paseos
 * @param clientes
 */
void getComparacionLocalidadTam(Lista<Paseo> paseos, Lista <Cliente> clientes);
    
/**
 * @param paseos
 */
void getComparacionLocalidadHorario(Lista <Paseo> paseos);
    
/**
 * Estadisticas 1
 * @param paseos
 */
void getReporteDiarioTotal(Lista <Paseo> paseos);
    
/**
 * Estadisticas 2
 * @param paseos
 */
void getReportePorLocalidad(Lista <Paseo> paseos);
    
/**
 * Estadisticas 3
 * @param paseos
 */
void getReportePorPaseador(Lista <Paseo> paseos);
};

#endif //_SIMULACION_H