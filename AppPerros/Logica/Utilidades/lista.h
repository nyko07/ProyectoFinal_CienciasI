#ifndef LISTA_H
#define LISTA_H

// Lista simple
template <class T>
struct nodo{
	T dato;
	nodo <T> *sig;
};

template <class T>
class Lista{
	private:
		nodo <T> *cab;
		int tam;
        nodo<T> *recorrer_lista(int fin);			
	
	public: 
	
		Lista(){
			cab = NULL;
			tam = 0;
		}		
		void insertar_nodo(int pos,T dato);		
		void borrar_nodo(int pos);
		void insertar_inicio(T dato);
		void insertar_final (T dato);
		T buscar(int pos);
		void cambiar(int pos,T dato);
		int getTam();
		
		
	
};

template <class T>
void Lista<T>::insertar_nodo(int pos, T dato){	
	int cont;
	
	if(pos==1){
		insertar_inicio(dato);	
	}else if(pos> tam)	{
		insertar_final(dato);
	}
	else{
		nodo<T> *nuevo, *aux;
		nuevo = new nodo<T>;
		nuevo -> dato = dato;
		/*aux = cab;
		cont =1;
		while(cont<pos-1 && aux!=NULL){
			aux=aux -> sig;
			cont++;
		}*/
		aux = recorrer_lista(pos-1);		
		nuevo->sig = aux-> sig;		
		aux -> sig = nuevo;
		tam++;
				
	}
}

template <class T>
void Lista<T>::insertar_final(T dato){
	nodo<T> *nuevo, *aux;
	nuevo = new nodo<T>;
	nuevo -> dato = dato;
	/*aux = cab;
	int cont=1;
	while(cont<tam && aux!=NULL){
			aux=aux -> sig;
			cont++;
		}*/
	aux = recorrer_lista(tam);
	aux -> sig = nuevo;
	tam++;
}

template <class T>
void Lista<T>::insertar_inicio(T dato){
	nodo<T> *nuevo;
	nuevo = new nodo<T>;
	nuevo -> dato = dato;
	nuevo->sig = cab;
	cab = nuevo;
	tam++;
	
}

template <class T>
T Lista<T>::buscar(int pos){
	//int cont = 1;
	nodo<T> *aux;
	/*aux = cab;
	while(cont<pos){		
		aux = aux->sig;
		cont++;
	}*/
	aux = recorrer_lista(pos);
	return aux->dato;
}

template <class T>
int Lista<T>::getTam(){
	return tam;
}

template <class T>
void Lista<T>::borrar_nodo(int pos){
	//int cont = 1;
	nodo<T> *aux;
	//aux = cab;
	if(tam==1){
		cab=NULL;
	}else{
		/*while(cont<pos-1){		
			aux = aux->sig;
			cont++;
		}*/
        aux = recorrer_lista(pos-1);	
		aux->sig= aux->sig->sig;		
	}	
	tam--;
		
}

template <class T>
void Lista<T>::cambiar(int pos,T dato){
    /*int cont = 1;
    nodo<T> *aux;   
    aux = cab; 
    while(cont<pos){
        aux = aux->sig;
        cont++;
    }*/
    nodo<T> *aux;
    aux=recorrer_lista(pos);
    aux->dato = dato;
    
   
}

template <class T>
nodo<T> *Lista<T>::recorrer_lista(int fin){
    int cont = 1;
    nodo<T> *aux;
    aux=cab;
    while(cont<fin){
        aux = aux->sig;
        cont++;
    }    
    return aux;    
    
}


#endif
