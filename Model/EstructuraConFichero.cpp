#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char * nombre;
	int calInicio, calFin, numeroPaseadores, craInicio,craFin;
	
}localidades;

localidades *trab;

void vaciar(char temp[]);


int main(){
	int i,j;
	char temp[50];
	int cont;
	char aux;
	
	FILE*f;
	f = fopen("datos.txt","r");
	
	if(f==NULL){
		printf("No se abrio el archivo");
	}
	
	while(!feof(f)){
		fgets(temp,50,f);
		
		cont++;
	}
	rewind(f);
	
	trab = (localidades*)malloc(cont*sizeof(localidades));
	
	if(trab == NULL){
		printf("no se realizo la accion");
	}
	
	
	for(i = 0; !feof(f); i++){
		vaciar(temp);
		aux= '0';
		fgets(temp,50,f);
		
		char * pch = strtok(temp,"-");
		int n = 0;
		 while (pch != NULL){
    		if(n ==0){
    			trab[i].nombre = pch; 
			}
			if(n ==1){
    			trab[i].calInicio = atoi(pch); 
			}
			if(n ==2){
    			trab[i].calFin = atoi(pch); 
			}
			if(n ==3){
    			trab[i].numeroPaseadores = atoi(pch); 
			}
			if(n ==4){
    			trab[i].craInicio = atoi(pch); 
			}
			if(n ==5){
    			trab[i].craFin = atoi(pch); 
			}
    		pch = strtok (NULL, "-");
    		n++;
  		}
		
	printf("nombre: %s calleInicio: %i calleFin: %i numeroPaseadores: %i craInicio: %i crFin: %i.\n", trab[i].nombre,trab[i].calInicio,trab[i].calFin,trab[i].numeroPaseadores,trab[i].craInicio,trab[i].craFin);
	}
	
	return 0;
}
void vaciar(char temp[]){
 	int i = 0;
 	for(i = 0 ; i<50;i++){
 		temp[i]== '\0';
	 }
 }






