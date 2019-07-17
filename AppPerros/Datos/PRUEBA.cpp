

#include <iostream>
#include "ArchivosPerros.h"
#include "ArchivosLocalidades.h"
#include <string>
#include "../Logica/Utilidades/Arbolrb.h"
#include "../Logica/Utilidades/lista.h"
#include "../Logica/Utilidades/Arbolrb.h"
#include "../Logica/Utilidades/Arbolrb.h"
#include "../Logica/Utilidades/Date.h"
#include "../Logica/Perro.h"



using namespace std;

int main(){
	
	Date fecha;
	Lista< Lista<string> >	listaPerros; 
	
	string id;
    string nombre;
    string idCliente;
    string f;
    string [] fe;
    Date fechaNacimiento;
    string raza;
    string tamanio;
    string tipoConcentrado;
	
	
	ArchivosPerros p;
	Perro perros;
	
	Arbolrb = rb;
	
	int j = 1;

	//p.guardarDatos("10322","132","12","buldog",'c',"duro");
	
	y = p.cargarDatos();
	listaPerros = p.cargarDatos();
	
	for(int i=1;i<=y.getTam();i++){
		
		
		id=listaPerros.buscar(i).buscar(j);
		j++;
		nombre = listaPerros.buscar(i).buscar(j);
		j++;	
		idCliente = listaPerros.buscar(i).buscar(j);
		j++;
		f = listaPerros.buscar(i).buscar(j);
			
			fe=f.Split('/');
			fechaNacimiento = Date(Integer.valueOf(fe[0]),Integer.valueOf(fe[1]),Integer.valueOf(fe[2]));
		
		
		j++;
		raza = listaPerros.buscar(i).buscar(j);
		j++;
		tamanio = listaPerros.buscar(i).buscar(j);
		j++;
		tipoConcentrado = listaPerros.buscar(i).buscar(j);
		
		perros = Perro(id,fechaNacimiento,raza,tamanio.charArt(0),tipoConcentrado,idCliente);

		rb.insert(perros,id);
		
		j = 0;			
	}
	
	
	
	
	
	
   return 0;
}
