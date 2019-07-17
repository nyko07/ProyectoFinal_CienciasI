/**
 * Project Untitled
 */


#ifndef _SIMULACION_H
#define _SIMULACION_H

#include "../Utilidades/lista.h"
#include "../Utilidades/Date.h"

#include "../Persona/Cliente.h"
#include "../Persona/Paseador.h"
#include "../Localidad.h"
#include "../Sucursal.h"
#include "../Paseo.h"
#include "../Perro.h"
#include "./Simulacion.h"
#include "../Utilidades/Arbolrb.h"

#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

class Simulacion {
private:
	Lista<Paseo> paseos;
public: 
    
    Simulacion(Lista<Paseo> p){
    	paseos = p;    	
	}
/**
 * @param paseos
 * @param clientes
 */
void getComparacionLocalidadTam(Lista<Localidad> localidades,RBtree <Cliente,string> clientes);
    
/**
 * @param paseos
 */
void getComparacionLocalidadHorario(Lista <Paseo> paseos);
    
/**
 * Estadisticas 1
 * @param paseos
 */
void getReporteDiarioTotal(RBtree <Cliente,string> clientes);
    
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

void simular();

Lista<Paseo> getPaseosPorLocalidad(string l);

Lista<Paseo> getPaseosFecha(Date fecha);
};

void Simulacion::simular(){
	for(int i=1;i<=paseos.getTam();i++){
		Date actual = Date();
		Paseo p = paseos.buscar(i);
		if(actual.getAnio()==p.getFecha().getAnio()){
			if(actual.getMes()==p.getFecha().getMes()){
				if(actual.getDia()==p.getFecha().getDia()&&p.getEstado()!='N'){
					p.setEstado('C');
				}
			}
		}		
	}
}

/**
 * @param paseos
 * @param clientes
 * @return void
 */
void Simulacion::getComparacionLocalidadTam(Lista<Localidad> localidades,RBtree <Cliente,string> clientes) {
	cout<<"Por tamaño porcentaje de atendidos"<<endl;
	Date actual = Date();
	for(int i=1;i<=localidades.getTam();i++){
		
		int pPerrosAten = 0;
		int pPerrosAtenE = 0;
		int mPerrosAten = 0;
		int mPerrosAtenE = 0;
		int gPerrosAten = 0;
		int gPerrosAtenE = 0;
		string nombreL = localidades.buscar(i).getNombre();
		cout<<"LOCALIDAD: "<<nombreL<<endl;
		Lista<Paseo> paseosL = getPaseosPorLocalidad(nombreL);
		
		for(int j=1;j<=paseosL.getTam();j++){
			if(paseosL.buscar(j).getEstado()=='C'){
				
				if(paseosL.buscar(j).getFecha().getDia()==actual.getDia() 
				&& paseosL.buscar(j).getFecha().getMes()==actual.getMes() 
				&& paseosL.buscar(j).getFecha().getAnio()==actual.getAnio()){
					
					Lista<Perro> perrosL = paseos.buscar(j).getPerros();
					for(int k=1;k<=perrosL.getTam();k++){
						Perro p = perrosL.buscar(k);
						Cliente c = clientes.search(p.getIdCliente())->key;
						
						if(c.getLocalidad()==nombreL){
							
							if(p.getTamano()=='P'){
								pPerrosAten++;					
							}else if(p.getTamano()=='M'){
								mPerrosAten++;
							}else if(p.getTamano()=='G'){
								gPerrosAten++;
							}
							
						}else{
							
							if(p.getTamano()=='P'){
								pPerrosAtenE++;					
							}else if(p.getTamano()=='M'){
								mPerrosAtenE++;
							}else if(p.getTamano()=='G'){
								gPerrosAtenE++;
							}
							
						}
						
						
					}
					
				}
				
				
			}
						
			
		}
		
		int total = pPerrosAten + pPerrosAtenE + mPerrosAten +mPerrosAtenE+gPerrosAten+gPerrosAtenE;
		cout<<"----------------------"<<endl;
		cout<<"Perros Pequeños"<<endl>
		cout<<"----------------------"<<endl;
		cout<<"Atendidos:\t"<<pPerrosAten<<"-"<<(pPerrosAten/total)*100<<"%"<<endl;
		cout<<"Externos:\t"<<pPerrosAtenE<<"-"<<(pPerrosAtenE/total)*100<<"%"<<endl;
		
		cout<<"----------------------"<<endl;
		cout<<"Perros Medianos"<<endl>
		cout<<"----------------------"<<endl;
		cout<<"Atendidos:\t"<<mPerrosAten<<"-"<<(mPerrosAten/total)*100<<"%"<<endl;
		cout<<"Externos:\t"<<mPerrosAtenE<<"-"<<(mPerrosAtenE/total)*100<<"%"<<endl;
		
		cout<<"----------------------"<<endl;
		cout<<"Perros Grandes"<<endl>
		cout<<"----------------------"<<endl;
		cout<<"Atendidos:\t"<<gPerrosAten<<"-"<<(gPerrosAten/total)*100<<"%"<<endl;
		cout<<"Externos:\t"<<gPerrosAtenE<<"-"<<(gPerrosAtenE/total)*100<<"%"<<endl;
		
	}
	
	return;
}

Lista<Paseo> Simulacion::getPaseosPorLocalidad(string l){
	Lista<Paseo> paseoL;
	for(int i=1;i<=paseos.getTam();i++){
		if(paseos.buscar(i).getLocalidad()==l){
			paseoL.insertar_nodo(paseoL.getTam()+1,paseos.buscar(i));
		}
	}
	return paseoL;
}



/**
 * @param paseos
 * @return void
 */
void Simulacion::getComparacionLocalidadHorario(Lista <Paseo> paseos) {
    return;
}

Lista<Paseo> Simulacion::getPaseosFecha(Date fecha){
	Lista<Paseo> paseosF;
	for(int i=1;i<=paseos.getTam();i++){
  		Paseo pas = paseos.buscar(i);  		
		if(pas.getFecha().getAnio()==fecha.getAnio()){
			if(pas.getFecha().getMes()==fecha.getMes()){
  				if(pas.getFecha().getDia()==fecha.getDia()){
  					paseosF.insertar_nodo(paseosF.getTam()+1,pas);	  				
			  	}
		  	}
		}  		
	}
	return paseosF;
}

/**
 * Estadisticas 1
 * @param paseos
 * @return void
 */
void Simulacion::getReporteDiarioTotal(RBtree <Cliente,string> clientes) {
	Date fecha = Date();
    Lista<Paseo> paseosF = getPaseosFecha(fecha);
    int tPAtendidos = 0;
    int tNoAtendidos = 0;
    int tMismaLocalidad = 0;
    int tDiferLocalidad = 0;
    cout<<"Reporte Diario Total"<<endl;
    cout<<"----------------------"<<endl;
    for(int i=1;i<=paseosF.getTam();i++){
    	Paseo p = paseosF.buscar(i);
    	for(int j=1;j<=p.getPerros().getTam();j++){
    		Perro pe = p.getPerros().buscar(j);
    		Cliente c = clientes.search(pe.getIdCliente())->key;
    		if(p.getEstado()=='C'){
    			tPAtendidos++;
			}
			if(p.getEstado()=='N'){
				tNoAtendidos++;
			}
			if(c.getLocalidad() == p.getLocalidad()){
				tMismaLocalidad++;
			}else{
				tDiferLocalidad++;
			}
		}
	}
	
	int total = tPAtendidos+tNoAtendidos;
	
	cout<<"Total Perros Atendidos: "<<tPAtendidos<<"-"<<(tPAtendidos/total)*100<<"%"<<endl;
	cout<<"Total Perros No Atendidos: "<<tNoAtendidos<<"-"<<(tNoAtendidos/total)*100<<"%"<<endl;
	cout<<"Total Perros Atendidos misma localidad: "<<tMismaLocalidad<<"-"<<(tMismaLocalidad/total)*100<<"%"<<endl;
	cout<<"Total Perros Atendidos distinta localidad: "<<tDiferLocalidad<<"-"<<(tDiferLocalidad/total)*100<<"%"<<endl;
}

/**
 * Estadisticas 2
 * @param paseos
 * @return void
 */
void Simulacion::getReportePorLocalidad(Lista <Paseo> paseos) {
    return;
}

/**
 * Estadisticas 3
 * @param paseos
 * @return void
 */
void Simulacion::getReportePorPaseador(Lista <Paseo> paseos) {
    return;
}

#endif //_SIMULACION_H
