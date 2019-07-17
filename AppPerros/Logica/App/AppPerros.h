/**
 * Project Untitled
 */


#ifndef _APPPERROS_H
#define _APPPERROS_H

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


class AppPerros {
	
	

private: 
    Simulacion simulacion;
    //Archivos  archivos;
    RBtree<Localidad,string> localidades;
    Lista <Paseo> paseos;
    RBtree <Cliente,string> clientes;
    RBtree <Sucursal, string> sucursales;
    RBtree <Paseador, string> paseadores;
    RBtree <Perro, string> perros;
    
public:
	AppPerros(){
		paseos = Lista<Paseo>();
	}
	
	//setter
	void setLocalidades(RBtree<Localidad,string> l){localidades = l;}
	void setClientes(RBtree<Cliente,string> l){clientes = l;}
	void setPaseadores(RBtree<Paseador,string> l){paseadores = l;}
	void setPerros(RBtree<Perro,string> l){perros = l;}
	void setPaseos(Lista<Paseo> p){paseos = p;}
	
	//getter
	RBtree<Localidad,string> getLocalidades(){return localidades;}
	RBtree<Cliente,string> getClientes(){return clientes;}
	RBtree<Paseador,string> getPaseadores(){return paseadores;}
	RBtree<Perro,string> getPerros(){return perros;}
	Lista<Paseo> getPaseos(){return paseos;}
	
	
	/**
	 * Memoria Principal 6
	 * @param n
	 */
	Lista <Cliente> clienteMasPerros(int n);
	
	/**
		 * Memoria Principal 9
		 * @param n
		 */
	void getPerrosCumple(int  n);  
/**
	 * Consultas 1
	 * @param clIni
	 * @param clFin
	 * @param crIni
	 * @param crFin
	 */
	Lista <Sucursal> getAreaSucursales(int clIni, int clFin, int crIni, int crFin);
	    
	/**
	 * Consultas 2
	 * @param dia
	 */
	Lista <Paseador> getPaseadoresDisponibles2(Dia dia);
	    
	/**
	 * Consultas 4
	 * @param localidad
	 * @param raza
	 */
	Lista <Cliente> getPerrosRaza(string  localidad, string  raza);
	    
	/**
	 * Consultas 5
	 * @param tm hIni
	 * @param tm hFin
	 */
	Lista <Paseo> getDatosPerroPaseo(string idPas, Date fIni, Date fFin);
	    
	/**
	 * Consultas 6
	 * @param idPerro
	 */
	Lista <Paseo> getPaseadores(string  idPerro, Date fIni, Date fFin);
	    
	/**
	 * Consultas 7
	 * @param localidad
	 * @param tam
	 */
	Lista <Perro> getPerrosTam(string  localidad, char  tam);
	    
	/**
	 * Consultas 3
	 * @param cliente
	 * @param dia
	 */
	Lista <Paseador> getPaseadoresDisponibles(string idCliente, Date fecha, int hIni, int hFin);
	    
	/**
	 * Consultas 8
	 * @param rangoIni
	 * @param rangoFin
	 */
	void getPerrosEdad(int rangoIni, int rangoFin);
	    
	/**
	 * @param cliente
	 * @param perro
	 * @param horario
	 */
	bool reservar(Cliente cliente, Perro perro, Dia horario);
	
	Lista<Paseo> getPaseosFecha(Date fecha);
};



/**
 * Memoria Principal 6
 * @param n
 * @return Lista <Clientes>
 */
Lista <Cliente> AppPerros::clienteMasPerros(int n) {
	clientes.arbolToLista();
	Lista<Cliente> clientesMas;
	Lista<Cliente> cs = clientes.getLista();
	
	for(int i=1;i<=cs.getTam();i++){
		if(cs.buscar(i).getPerros().getTam()>=2){
			clientesMas.insertar_nodo(clientesMas.getTam()+1,cs.buscar(i));
		}
	}
	return clientesMas;
	  
}

/**
 * Memoria Principal 9
 * @param n
 * @return void
 */
void AppPerros::getPerrosCumple(int  n) {
	perros.arbolToLista();
	//Lista<Perro> perrosCum;
	cout<<"Cumpleaños perros"<<endl;
	cout<<"Nombre Perro\t"<<"Localidad\t"<<"Mes\t"<<"Dia"<<endl;
	for(int i=1;i<=perros.getLista().getTam();i++){
		if(perros.getLista().buscar(i).getFechaNacimiento().getMes() == n){
			//perrosCum.insertar_nodo(perrosCum.getTam()+1,perros.getLista().buscar(i));
			Cliente cliente = clientes.search(perros.getLista().buscar(i).getIdCliente())->key;
			cout<<perros.getLista().buscar(i).getNombre()<<"\t"<<cliente.getLocalidad()<<perros.getLista().buscar(i).getFechaNacimiento().getMesT()<<perros.getLista().buscar(i).getFechaNacimiento().getDia()<<endl;			
		}
	}
    //return perrosCum;
}


/**
 * Consultas 1
 * @param clIni
 * @param clFin
 * @param crIni
 * @param crFin
 * @return Lista <Sucursal>
 */
Lista <Sucursal> AppPerros::getAreaSucursales(int clIni, int clFin, int crIni, int crFin) {
    return Lista<Sucursal>();
}

/**
 * Consultas 2
 * @param dia
 * @return Lista <Paseador>
 */
Lista <Paseador> AppPerros::getPaseadoresDisponibles2(Dia dia) {
    return Lista<Paseador>();
}

/**
 * Consultas 4
 * @param localidad
 * @param raza
 * @return Lista <Cliente>
 */
Lista <Cliente> AppPerros::getPerrosRaza(string  localidad, string  raza) {
    Localidad l = localidades.search(localidad)->key;
    Lista<Cliente> clientesRa;
    for(int i=1;i<=l.getPerros().getTam();i++){
    	if(l.getPerros().buscar(i).getRaza()==raza){
    		Cliente c = (clientes.search(l.getPerros().buscar(i).getIdCliente()))->key;
    		clientesRa.insertar_nodo(clientesRa.getTam()+1,c);
		}   	
    	
	}
	
	return clientesRa;
}

/**
 * Consultas 5
 * @param tm hIni
 * @param tm hFin
 * @return Lista <Paseo>
 */
Lista <Paseo> AppPerros::getDatosPerroPaseo(string idPas, Date fIni, Date fFin) {
  	Lista<Paseo> paseosF;	
  	for(int i=1;i<=paseos.getTam();i++){
  		Paseo pas = paseos.buscar(i);
  		if(pas.getPaseador().getId()==idPas){
  			if(pas.getFecha().getAnio()<=fFin.getAnio() && pas.getFecha().getAnio()>=fIni.getAnio()){
  				if(pas.getFecha().getMes()<=fFin.getMes() && pas.getFecha().getMes()>=fIni.getMes()){
	  				if(pas.getFecha().getDia()<=fFin.getDia() && pas.getFecha().getDia()>=fIni.getDia()){
	  					paseosF.insertar_nodo(paseosF.getTam()+1,pas);	  				
				  	}
			  	}
			}
  			
		}
  		
	}
	
	return paseosF;
}

/**
 * Consultas 6
 * @param idPerro
 * @return Lista <Paseo>
 */
Lista <Paseo> AppPerros::getPaseadores(string  idPerro, Date fIni, Date fFin) {
	
	Lista<Paseo> paseosF;	
  	for(int i=1;i<=paseos.getTam();i++){
  		Paseo pas = paseos.buscar(i);
  		for(int j=1;j<=pas.getPerros().getTam();j++){
  			if(pas.getPerros().buscar(j).getId()==idPerro){
	  			if(pas.getFecha().getAnio()<=fFin.getAnio() && pas.getFecha().getAnio()>=fIni.getAnio()){
	  				if(pas.getFecha().getMes()<=fFin.getMes() && pas.getFecha().getMes()>=fIni.getMes()){
		  				if(pas.getFecha().getDia()<=fFin.getDia() && pas.getFecha().getDia()>=fIni.getDia()){
		  					paseosF.insertar_nodo(paseosF.getTam()+1,pas);	  				
					  	}
				  	}
				}
				break;	  			
			}	
		}
  		
  		
	}
	
	return paseosF;
}

/**
 * Consultas 7
 * @param localidad
 * @param tam
 * @return Lista <Perro>
 */
Lista <Perro> AppPerros::getPerrosTam(string  localidad, char  tam) {
    Localidad l = (localidades.search(localidad))->key;
    Lista<Perro> perrosF;
    for(int i=1;i<=l.getPerros().getTam();i++){
    	if(l.getPerros().buscar(i).getTamano()==tam ){
    		perrosF.insertar_nodo(perrosF.getTam()+1,l.getPerros().buscar(i));
		}
	}
	
	return perrosF;
}

/**
 * Consultas 3
 * @param cliente
 * @param dia
 * @return Lista <Paseador>
 */
Lista <Paseador> AppPerros::getPaseadoresDisponibles(string idCliente, Date fecha, int hIni, int hFin) {
    Cliente c = (clientes.search(idCliente))->key;
    int numPerros = c.getPerros().getTam();
    paseadores.arbolToLista();
    Lista<Paseador> pases = paseadores.getLista();
    Lista<Paseador> paseadoresDispo;
    Lista<Paseo> paseosF = getPaseosFecha(fecha);
    for (int i=1;i<=pases.getTam();i++){
    	Paseador p = pases.buscar(i);
    	int cont=0;
    	for(int j=1;j<=paseosF.getTam();j++){
    		Paseo pa = paseosF.buscar(j);    		
    		if(pa.getPaseador().getId()==p.getId()){
    			if(!(hFin<pa.getHoraIni() || hIni>pa.getHoraFin())){
    				cont++;
				}
			}
		}
		if(cont==0){
			paseadoresDispo.insertar_nodo(paseadoresDispo.getTam()+1,p);	
		}   	
	}
	
	return paseadoresDispo;
}

Lista<Paseo> AppPerros::getPaseosFecha(Date fecha){
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
 * Consultas 8
 * @param rangoIni
 * @param rangoFin
 * @return void
 */
void AppPerros::getPerrosEdad(int rangoIni, int rangoFin) {
    
}

/**
 * @param cliente
 * @param perro
 * @param horario
 * @return bool
 */
bool AppPerros::reservar(Cliente cliente, Perro perro, Dia horario) {
    return false;
}

#endif //_APPPERROS_H
