#include <iostream>
#include "ArchivosPerros.h"
#include <string>


using namespace std;

int main(){
	
	string ** y; 
	ArchivosPerros p;
	//p.guardarDatos("10322","132","12","buldog",'c',"duro");
	y = p.cargarDatos();

	std::cout<<"------------>"<<y[0][0];

   return 0;
}
