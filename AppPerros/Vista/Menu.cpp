#include <iostream>

#include "../Logica/App/AppPerros.h"
#include "../Logica/Persona/Cliente.h"
#include "../Logica/Persona/Persona.h"
#include "../Logica/Persona/Paseador.h"
#include "../Logica/Perro.h"
#include "../Logica/Paseo.h"
#include "../Logica/Sucursal.h"
#include "../Logica/Utilidades/Date.h"
#include "../Logica/Utilidades/Lista.h"
#include "../Logica/Utilidades/Arbolrb.h"
#include "../Logica/Persona/Persona.h"
//#include "../Datos/ArchivosClientes.h"
//#include "../Datos/ArchivosPersonas.h"

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
int perro();
bool registrarCliente();
void verCliente();
bool editarCliente();
bool eliminarCliente();
bool registrarPaseador();
void verPaseador();
bool editarPaseador();
bool eliminarPaseador();

//Metodos de prueba
void consulta1();
void consulta2();
void consulta3();
void consulta4();
void consulta5();
void consulta6();
void consulta7();
void consulta8();

int Perro::idActual;
int Dia::idActual;
int Paseo::idActual;
int Sucursal::idActual;

Persona p;
Cliente c;
Paseador pase;
Perro per;
Lista<Perro> listaPerros;
int numeroPerros = 0;
int temp = 0;

AppPerros appPerros = AppPerros();


int main(int argc, char** argv) {
	
	
	//Perro::idActual = 0;
	//Date date1 = Date(2, 10, 2015);
	//Perro p = Perro(date1,"ptbull", 'p', "Carnehumana", "1234");
	//c.addPerro(p);
	//Date date2 = Date(4, 6, 2014);
	//Paseador pa = Paseador("Marce", "Rubi", "31234", "2334", 'd', "ffsdf", "dfdsf", date2, "cali", "Colo", "dfsf22", "via");
	//Paseo pase = Paseo(2, 12, "Caminata", "patio", "bueno");
	//Sucursal sucu = Sucursal("Aviva", "yo");
	

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
	
	//Cliente c = Cliente("Nicolas", "Herrera", "3243433", "543345", 'd', "1234", "cedu", "Bulgaria");
	
	//clientes=appPerros.getClientes
	
	
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
	    cout<<"5. Salir"<<endl;
	    cin>>opc;
        
        switch(opc){
            case 1:
                registrarCliente();
                break;    
            case 2:
                verCliente();
                break;
			case 3:
                editarCliente();
                break;    
            case 4:
                eliminarCliente();
                break;    
        }
                
    }while(opc != 5);	
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
                registrarPaseador();
                break;    
            case 2:
                verPaseador();
                break;
			case 3:
                editarPaseador();
                break;    
            case 4:
                eliminarPaseador();
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

//--------------------------------------------------------------------------------------------------------------------------------
//Metodos CRUD de prueba para el menú
//CRUD Cliente
bool registrarCliente(){
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tCliente"<<endl;
    cout<<"\tRegistrar"<<endl;
	cout<<"<========================================>"<<endl;
	
	string id, tipoId, nombre, apellido, telefono, celular, email, localidad;
	char sexo;
	
	cout<<"Ingrese nombre: ";
	cin>>nombre;
	cout<<endl;
	
	cout<<"Ingrese apellido: ";
	cin>>apellido;
	cout<<endl;
	
	cout<<"Ingrese telefono: ";
	cin>>telefono;
	cout<<endl;
	
	cout<<"Ingrese celular: ";
	cin>>celular;
	cout<<endl;
	
	cout<<"Ingrese sexo: ";
	cin>>sexo;
	cout<<endl;
	
	cout<<"Ingrese id: ";
	cin>>id;
	cout<<endl;
	
	cout<<"Ingrese Tipo Id: ";
	cin>>tipoId;
	cout<<endl;
	
	cout<<"Ingrese localidad: ";
	cin>>localidad;
	cout<<endl;
	
	Cliente c;
	
	c = Cliente(nombre, apellido, telefono, celular, sexo, id, tipoId,localidad,email);
	
	
	
	cout<<"Ingrese cantidad de perros a registrar: ";
	cin>>temp;
	cout<<endl;
	
	
    cout<<"Registro Perro"<<endl;	
	int opc;
	
	
	for(numeroPerros = 0;numeroPerros>temp;numeroPerros++){
        opc = perro();   
    }
    
    //AGREGAR CLIENTE ARBOL
    appPerros.getClientes().insert(c,c.getId());
    
    numeroPerros = 0;
    
    system("pause");
    
	return true;
}

int perro(){
	
    system("cls");
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tRegistrar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<"Agregar perro"<<endl;
	cout<<"------------------------------------------"<<endl;   
    int opc;
    
    
    Perro perro;
    string idPerro, raza, tipoConcentrado,nombre;
    Date fechaNacimiento;
    int dia,mes,anio;
    char tamano;
    
    cout<<"Ingrese nombre: ";
	cin>>nombre;
	cout<<endl;
	
	cout<<"Ingrese fecha nacimiento"<<endl;
	cout<<"Dia: ";
	cin>>dia;
	cout<<"Mes: ";
	cin>>mes;
	cout<<"Anio: ";
	cin>>anio;
	fechaNacimiento = Date(dia,mes,anio);
	cout<<endl;
	
	cout<<"Ingrese raza: ";
	cin>>raza;
	cout<<endl;
	
	cout<<"Ingrese tamano: ";
	cin>>tamano;
	cout<<endl;
	
	cout<<"Ingrese tipo de concentrado: ";
	cin>>tipoConcentrado;
	cout<<endl;
    
    int idCliente;
    perro = Perro(nombre, fechaNacimiento, raza, tamano, tipoConcentrado, c.getId());    
    
    if(numeroPerros == 0 ){
    	listaPerros.insertar_inicio(perro);
	}
	if(numeroPerros == temp){
		listaPerros.insertar_nodo(numeroPerros,perro); 
	}else{
		listaPerros.insertar_nodo(numeroPerros,perro);
	}
	
    
    
       
    
    cout<<"Desea ingresar mas Perros? 0:no y 1:si ";
    cin>>opc;
    cout<<endl;
    return opc;
}

void verCliente(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tVer"<<endl;
	cout<<"<========================================>"<<endl;
	     

	//cout<<"Id: "<<c.getId()<<endl;
	//cout<<"Nombre: "<<c.getNombre()<<endl;
	//cout<<"Apellido: "<<c.getApellido()<<endl;
	//cout<<"Telefono: "<<c.getTelefono()<<endl;
	//cout<<"Celular: "<<c.getCelular()<<endl;
	//cout<<"Sexo: "<<c.getSexo()<<endl;
	//cout<<"Localidad: "<<c.getLocalidad()<<endl;
	
	
	
	cout<<endl;
    
    system("pause");
	
}

bool editarCliente(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEditar"<<endl;
	cout<<"<========================================>"<<endl;
	
	cout<<"Ingrese el nombre: ";
	//string nombre;
	//cin>>nombre;
	//c.setNombre(nombre);
	//cout<<c.getNombre();
	
	cout<<endl;
    system("pause");
	
	return true;
}

bool eliminarCliente(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEliminar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
    
    system("pause");
	
	return true;
}

//CRUD Paseador
bool registrarPaseador(){
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tPaseador"<<endl;
    cout<<"\tRegistrar"<<endl;
	cout<<"<========================================>"<<endl;
	
	
	string id, tipoId, nombre, apellido, telefono, celular, email, ciudad, pais, direccion, barrio;
	char sexo;
	Date fecha;
	
	cout<<"Ingrese nombre: ";
	cin>>nombre;
	cout<<endl;
	
	cout<<"Ingrese apellido: ";
	cin>>apellido;
	cout<<endl;
	
	cout<<"Ingrese email: ";
	cin>>email;
	cout<<endl;
	
	cout<<"Ingrese telefono: ";
	cin>>telefono;
	cout<<endl;
	
	cout<<"Ingrese celular: ";
	cin>>celular;
	cout<<endl;
	
	cout<<"Ingrese sexo: ";
	cin>>sexo;
	cout<<endl;
	
	cout<<"Ingrese id: ";
	cin>>id;
	cout<<endl;
	
	cout<<"Ingrese Tipo Id: ";
	cin>>tipoId;
	cout<<endl;
	int dia,mes,anio;
	cout<<"Ingrese fecha"<<endl;
	cout<<"Dia: ";
	cin>>dia;
	cout<<"Mes: ";
	cin>>mes;
	cout<<"Anio: ";
	cin>>anio;
	fecha = Date(dia,mes,anio);
	cout<<endl;
	
	
	cout<<"Ingrese ciudad: ";
	cin>>ciudad;
	cout<<endl;
	
	cout<<"Ingrese pais: ";
	cin>>pais;
	cout<<endl;
	
	cout<<"Ingrese direccion: ";
	cin>>direccion;
	cout<<endl;
	
	cout<<"Ingrese barrio: ";
	cin>>barrio;
	cout<<endl;
	
	Paseador pase; 
	
	pase = Paseador(nombre, apellido, telefono, celular, sexo, id, tipoId, fecha,ciudad, pais, direccion, barrio, email);
	
    
    //AGREGAR PASEADOR ARBOL
    appPerros.getPaseadores().insert(pase,pase.getId());
    
	
    
    system("pause");
	return true;
}

void verPaseador(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tVer"<<endl;
	cout<<"<========================================>"<<endl;
	     

	//cout<<"Id: "<<c.getId()<<endl;
	//cout<<"Nombre: "<<c.getNombre()<<endl;
	//cout<<"Apellido: "<<c.getApellido()<<endl;
	//cout<<"Telefono: "<<c.getTelefono()<<endl;
	//cout<<"Celular: "<<c.getCelular()<<endl;
	//cout<<"Sexo: "<<c.getSexo()<<endl;
	//cout<<"Localidad: "<<c.getLocalidad()<<endl;
	
	
	
	cout<<endl;
    
    system("pause");
	
}

bool editarPaseador(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEditar"<<endl;
	cout<<"<========================================>"<<endl;
	
	cout<<"Ingrese el nombre: ";
	string nombre;
	cin>>nombre;
	//c.setNombre(nombre);
	//cout<<c.getNombre();
	
	cout<<endl;
    system("pause");
	
	return true;
}

bool eliminarPaseador(){
	
	system("cls");
    int pos;
    cout<<"\tAppPERROS"<<endl;
    cout<<"\tEliminar"<<endl;
	cout<<"<========================================>"<<endl;
	cout<<endl;
    
    system("pause");
	
	return true;
}
