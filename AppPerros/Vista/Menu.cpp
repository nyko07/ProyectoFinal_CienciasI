#include <iostream>


using namespace std;


void reserva();
void menuPersona();
void estadisticas();
void reporDiario();
void reporLocalidad();
void reporPaseador();
void consultas();
void cliente();
void paseador();
void perro();
bool registrar();
void ver();
bool editar();
bool eliminar();

//Metodos de prueba
void consulta1();
void consulta2();
void consulta3();
void consulta4();
void consulta5();
void consulta6();
void consulta7();
void consulta8();


int main(int argc, char** argv) {
	
	int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tMenu Principal"<<endl;
	    cout<<"<========================================>"<<endl;
	    
	    cout<<"1. Reserva"<<endl;
	    cout<<"2. Persona"<<endl;
	    cout<<"3. Estadisticas"<<endl;
	    cout<<"4. Consultas"<<endl;	    
	    cout<<"5. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                reserva();
                break;    
            case 2:
                menuPersona();
                break;
            case 3:
                estadisticas();
                break;
            case 4:
                consultas();
                break;        
        }
                
    }while(opc != 5);	
		
		
	system("pause");
	return 0;
}

void reserva(){
    system("cls");
    
    int cliente;
    int perro;
    int horario;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Realizar la reserva a continuacion:"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Nombre del cliente: ";
	cin>>cliente;
	cout<<endl;
	//Buscar el cliente
	
	cout<<"Nombre del perro: ";
	cin>>perro;
	cout<<endl;
	//Buscar el perro
	
	cout<<"Horario del paseo() :";
	cin>>horario;
	cout<<endl;
	//Poner el horario
	
	cout<<"....."<<endl;
	cout<<"Reserva realizada con exito!!"<<endl;
	cout<<endl;
	
	system("pause");
	
}

void estadisticas(){
    
    int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tEstadisticas"<<endl;
	    cout<<"<========================================>"<<endl;
	    
	    cout<<"1. Reporte diario total"<<endl;
	    cout<<"2. Reporte por localidad"<<endl;
	    cout<<"3. Reporte por paseador"<<endl;
	    cout<<"4. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                reporDiario();
                break;    
            case 2:
                reporLocalidad();
                break;
			case 3:
                reporPaseador();
                break;      
        }
                
    }while(opc != 4);	
	system("pause");
}

void consultas(){
	
    int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tConsultas"<<endl;
	    cout<<"<========================================>"<<endl;
	    
	    cout<<"1. Sucursales disponibles para perros"<<endl;
	    cout<<"2. Paseadores disponibles por localidad"<<endl;
	    cout<<"3. Paseadores que pueden hacerse cargo de perros"<<endl;
	    cout<<"4. Clientes con perros de una raza"<<endl;
	    cout<<"5. Perros con informacion de paseo"<<endl;
	    cout<<"6. Paseadores de un perro con informacion de paseo"<<endl;
	    cout<<"7. Lista de perros de una localidad (por tamano)"<<endl;
	    cout<<"8. Perros con un rango de edad"<<endl;
	    cout<<"9. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                consulta1();
                break;    
            case 2:
                consulta2();
                break;
			case 3:
                consulta3();
                break;
			case 4:
                consulta4();
                break;    
            case 5:
                consulta5();
                break;
			case 6:
                consulta6();
                break;  
			case 7:
                consulta7();
                break;    
            case 8:
                consulta8();
                break;      
        }
                
    }while(opc != 9);	
	system("pause");
    
}

void menuPersona(){
    int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tMenu Persona"<<endl;
	    cout<<"<========================================>"<<endl;
	    
	    cout<<"1. Cliente"<<endl;
	    cout<<"2. Paseador"<<endl;
	    cout<<"3. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                cliente();
                break;    
            case 2:
                paseador();
                break;    
        }
                
    }while(opc != 3);	
	system("pause");
    
}


void cliente(){
	
	int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tCliente"<<endl;
	    cout<<"<========================================>"<<endl;
	    cout<<"CRUD cliente"<<endl;
		cout<<"------------------------------------------"<<endl;
	    cout<<"1. Registrar"<<endl;
	    cout<<"2. Ver"<<endl;
	    cout<<"3. Editar"<<endl;
	    cout<<"4. Eliminar"<<endl;
	    cout<<"------------------------------------------"<<endl;
	    cout<<"5. Perro"<<endl;
	    cout<<"6. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                registrar();
                break;    
            case 2:
                ver();
                break;
			case 3:
                editar();
                break;    
            case 4:
                eliminar();
                break;
			case 5:
                perro();
                break;     
        }
                
    }while(opc != 6);	
	system("pause");
	
}

void paseador(){
    
    int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tPaseador"<<endl;
	    cout<<"<========================================>"<<endl;
	    cout<<"CRUD paseador"<<endl;
		cout<<"------------------------------------------"<<endl;
	    cout<<"1. Registrar"<<endl;
	    cout<<"2. Ver"<<endl;
	    cout<<"3. Editar"<<endl;
	    cout<<"4. Eliminar"<<endl;
	    cout<<"------------------------------------------"<<endl;
	    cout<<"5. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                registrar();
                break;    
            case 2:
                ver();
                break;
			case 3:
                editar();
                break;    
            case 4:
                eliminar();
                break;    
        }
                
    }while(opc != 5);	
	system("pause");
    
}

void perro(){
	
	int opc;
	
	do{
        system("cls");
        cout<<"\tAppPERROS"<<endl;
        cout<<"\tPerro"<<endl;
	    cout<<"<========================================>"<<endl;
	    cout<<"CRUD perro"<<endl;
		cout<<"------------------------------------------"<<endl;
	    cout<<"1. Registrar"<<endl;
	    cout<<"2. Ver"<<endl;
	    cout<<"3. Editar"<<endl;
	    cout<<"4. Eliminar"<<endl;
	    cout<<"------------------------------------------"<<endl;
	    cout<<"5. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                registrar();
                break;    
            case 2:
                ver();
                break;
			case 3:
                editar();
                break;    
            case 4:
                eliminar();
                break;     
        }
                
    }while(opc != 5);	
	system("pause");
	
}

void reporDiario(){
	
    system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEstadisticas"<<endl;
    cout<<"\tReporte diario total"<<endl;
	cout<<"<========================================>"<<endl;
	
	cout<<"Total de perros atendidos: ";
	//Metodo de los perros atendidos
	cout<<endl;
	
	cout<<"Total de perros que no se pudieron cubrir: ";
	//Metodo de los perros que no se pudieron cubrir
	cout<<endl;
	
	cout<<"Total servicios a la localidad a la que pertenecen: ";
	//Metodo de los servicios a la localidad a la que pertenecen
	cout<<endl;
	
	cout<<"Total servicios en una localidad diferente a la inscrita: ";
	//Metodo de los servicios en una localidad diferente a la inscrita
	cout<<endl;
    
    system("pause");
    
}

void reporLocalidad(){
	
    system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEstadisticas"<<endl;
    cout<<"\tReporte por localidad"<<endl;
	cout<<"<========================================>"<<endl;
	
	cout<<"Total de perros atendidos: ";
	//Metodo de los perros atendidos
	cout<<endl;
	
	cout<<"Total de perros que no se pudieron cubrir: ";
	//Metodo de los perros que no se pudieron cubrir
	cout<<endl;
	
	cout<<"Total servicios a la localidad a la que pertenecen: ";
	//Metodo de los servicios a la localidad a la que pertenecen
	cout<<endl;
	
	cout<<"Total servicios en una localidad diferente a la inscrita: ";
	//Metodo de los servicios en una localidad diferente a la inscrita
	cout<<endl;
    
    system("pause");
    
}

void reporPaseador(){
	
    system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEstadisticas"<<endl;
    cout<<"\tReporte por paseador"<<endl;
	cout<<"<========================================>"<<endl;
	
	cout<<"Total de perros atendidos: ";
	//Metodo de los perros atendidos
	cout<<endl;
	
	cout<<"Total de perros que no se pudieron cubrir: ";
	//Metodo de los perros que no se pudieron cubrir
	cout<<endl;
	
	cout<<"Total servicios a la localidad a la que pertenecen: ";
	//Metodo de los servicios a la localidad a la que pertenecen
	cout<<endl;
	
	cout<<"Total servicios en una localidad diferente a la inscrita: ";
	//Metodo de los servicios en una localidad diferente a la inscrita
	cout<<endl;
    
    system("pause");
    
}

//Metodos CRUD de prueba para el menú
bool registrar(){
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tRegistrar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
	
    
    system("pause");
	return true;
}

void ver(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tVer"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
    
    system("pause");
	
}

bool editar(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEditar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
    
    system("pause");
	
	return true;
}

bool eliminar(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEliminar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
    
    system("pause");
	
	return true;
}

void consulta1(){
	
	system("cls");
    
    int calleIni;
    int calleFin;
    int carreraIni;
    int carreraFin;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 1"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"calle inicio: ";
	cin>>calleIni;
	cout<<endl;
	
	cout<<"calle fin: ";
	cin>>calleFin;
	cout<<endl;
	
	cout<<"carrera inicio: ";
	cin>>carreraIni;
	cout<<endl;
	
	cout<<"carrera fin: ";
	cin>>carreraFin;
	cout<<endl;
	
	cout<<"Las sucursales que podrian hacerse cargo de perros en el area mencionada son:"<<endl;
	//Llamar al método para la primera consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta2(){
	
	system("cls");
    
    int horario;
    int localidad;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 2"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Horario(): ";
	cin>>horario;
	cout<<endl;
	
	cout<<"localidad: ";
	cin>>localidad;
	cout<<endl;
	
	
	cout<<"Paseadores disponibles:"<<endl;
	//Llamar al método para la segunda consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta3(){
	
	system("cls");
    
    int cliente;
    int horario;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 3"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"cliente: ";
	cin>>cliente;
	cout<<endl;
	
	cout<<"horario(): ";
	cin>>horario;
	cout<<endl;
	
	cout<<"Paseadores para hacerse cargo de sus perros:"<<endl;
	//Llamar al método para la tercera consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta4(){
	
	system("cls");
    
    int localidad;
    int raza;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 4"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"localidad: ";
	cin>>localidad;
	cout<<endl;
	
	cout<<"raza: ";
	cin>>raza;
	cout<<endl;
	
	
	cout<<"Perros:"<<endl;
	//Llamar al método para la cuarta consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta5(){
	
	system("cls");
    
    int paseador;
    int horario;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 5"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Paseador: ";
	cin>>paseador;
	cout<<endl;
	
	cout<<"Horario(): ";
	cin>>horario;
	cout<<endl;
	
	
	cout<<"Perros con la información del paseo:"<<endl;
	//Llamar al método para la quinta consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta6(){
	
	system("cls");
    
    int perro;
    int horario;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 6"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Perro: ";
	cin>>perro;
	cout<<endl;
	
	cout<<"Horario(): ";
	cin>>horario;
	cout<<endl;
	
	cout<<"Paseadores con informacion de paseo:"<<endl;
	//Llamar al método para la sexta consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta7(){
	
	system("cls");
    
    int localidad;
    int tamano;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 1"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Localidad: ";
	cin>>localidad;
	cout<<endl;
	
	cout<<"Tamano (grande,mediano,pequeno): ";
	cin>>tamano;
	cout<<endl;
	
	cout<<"Perros con las condiciones anteriores:"<<endl;
	//Llamar al método para la septima consulta
	cout<<endl;
	
	system("pause");
	
}

void consulta8(){
	
	system("cls");
    
    int edadMin;
    int edadMax;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tReserva"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Consulta 8"<<endl;
	cout<<"------------------------------------------"<<endl;
	
	cout<<"Edad minima: ";
	cin>>edadMin;
	cout<<endl;
	
	cout<<"Edad maxima: ";
	cin>>edadMax;
	cout<<endl;
	
	
	cout<<"Perros en ese rango:"<<endl;
	//Llamar al método para la octava consulta
	cout<<endl;
	
	system("pause");
	
}
