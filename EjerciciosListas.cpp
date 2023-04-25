#include "EjerciciosListas.h"

NodoLista* invertirParcial(NodoLista* l) 
{

	if (l->sig == NULL) {
		return NULL;
	}
	int n = 1;
	NodoLista* anteUltimo = l;
	while (anteUltimo->sig->sig != NULL) {
		n++;
		anteUltimo = anteUltimo->sig;
	}

	NodoLista* iniciNuevaLista = new NodoLista;
	iniciNuevaLista->dato = anteUltimo->dato;
	iniciNuevaLista->sig = NULL;
	anteUltimo = l;
	NodoLista* ultimoNueva = iniciNuevaLista;
	n--;

	while (n>=1) {
		int  tempo = 1;
		while (tempo != n)
		{
			anteUltimo = anteUltimo->sig;
			tempo++;
		}

		NodoLista* nuevo = new NodoLista;
		nuevo->dato = anteUltimo->dato;
		nuevo->sig = NULL;

		ultimoNueva->sig = nuevo;
		ultimoNueva = nuevo;

		anteUltimo = l;
		n--;
	}
	
	
	return iniciNuevaLista;
}


void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	if (!lista) return;

	if (lista->sig) {
		//sigo aumentando la pila de llamadas
		eliminarNesimoDesdeElFinal(lista->sig, n);
		if (n == 1) {
			//elimino este elemento
			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;
		}
	}
	else {
		//llegue al final de la lista
		if (n == 1) {
			//elimino este elemento
			NodoLista* aux = lista;
			lista = lista->sig;
			delete aux;
		}
	}
	//cuenta regresiva
	n--;
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{

	if (l == NULL) {
		return NULL;
	}
	NodoLista* nueva = new NodoLista;
	nueva->dato = l->dato;
	NodoLista* aux = nueva;

	while (l->sig != NULL) {
		l = l->sig;
		aux->sig = new NodoLista;
		aux = aux->sig;
		aux->dato = l->dato;
	}

	aux = nueva->sig;
	NodoLista* left = nueva;
	NodoLista* right = aux;

	while (aux!=NULL) {
		
		if (right->dato < left->dato) {
			//cambio
			int x = left->dato;
			left->dato = right->dato;
			right->dato = x;
			//retroceso de punteros(hasta el inicio de la lista)
			left = nueva;
			right = nueva->sig;
			aux = nueva->sig;
		}
		else {
			aux = aux->sig;
			right = right->sig;
			left = left->sig;
		}

	}
	

	return nueva;
	
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	NodoLista* menor = NULL;
	NodoLista* iterador = NULL;
	NodoLista* ultimoEvaluado = l;
	NodoLista* ultimoOrdenado = l;

	if (l == NULL) {
		return;
	}

	while (ultimoOrdenado->sig != NULL) {
		menor = ultimoOrdenado;
		iterador = ultimoOrdenado;
		while (iterador != NULL) {
			if (iterador->dato < menor->dato) {
				menor = iterador;
			}
			iterador = iterador->sig;
		}

		if (ultimoOrdenado->dato > menor->dato) {
			int valAux = ultimoOrdenado->dato;
			ultimoOrdenado->dato = menor->dato;
			menor->dato = valAux;
		}

		ultimoOrdenado = ultimoOrdenado->sig;
	}


	
}



NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* nuevo = NULL;

	if (!l1 && !l2) {
		return nuevo;
	}
	//defino el inicio de mi nueva lista
	if (l1 && l2) {
		if (l1->dato < l2->dato) {
			nuevo = new NodoLista(l1->dato);
			l1 = l1->sig;
		}
		else {
			nuevo = new NodoLista(l2->dato);
			l2 = l2->sig;
		}
	}
	else {
		if (l1) {
			nuevo = new NodoLista(l1->dato);
			l1 = l1->sig;
		}
		if (l2) {
			nuevo = new NodoLista(l2->dato);
			l2 = l2->sig;
		}
	}
	
	
	NodoLista* aux = nuevo;
	while (l1 || l2) {
		
		if (l1 && l2) {
			
			if (l1->dato < l2->dato) {
				//insert a, abanzo a
				aux->sig = new NodoLista(l1->dato);
				l1 = l1->sig;
			}
			else {
				//insert b, abanzo b
				aux->sig = new NodoLista(l2->dato);
				l2 = l2->sig;
			}
		}
		else {
			if (l1) {
				aux->sig = new NodoLista(l1->dato);
				l1 = l1->sig;
			}
			else if (l2) {
				aux->sig = new NodoLista(l2->dato);
				l2 = l2->sig;
			}
		}
		aux = aux->sig;
	}
	return nuevo;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
