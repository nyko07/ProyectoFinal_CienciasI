#include <iostream>
#include "ArchivosPerros.h"
#include <string>
#include "../Logica/Utilidades/lista.h"


using namespace std;

int main(){
	
	Lista< Lista<string> >y; 
	ArchivosPerros p;
	//p.guardarDatos("10322","132","12","buldog",'c',"duro");
	y = p.cargarDatos();
	
	for(int i=1;i<=y.getTam();i++){
		
		for(int j=1;j<=y.buscar(i).getTam();j++){
			cout<<y.buscar(i).buscar(j)<<endl;
		}
	}

   return 0;
}
