#include "EjerciciosArboles.h"


int altura(NodoAB* raiz){
	if (!raiz) {
		return 0;
	}

	int aIzq = altura(raiz->izq);
	int aDer = altura(raiz->der);

	int altMayor = aIzq > aDer ? aIzq : aDer;
	return 1 + altMayor;
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	// IMPLEMENTAR SOLUCION
	return false;
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (!raiz && sum>0) {
		return false;
	}else if (!raiz && sum==0) {
		return true;
	}

	int remanente = sum - raiz->dato;

	if (!raiz->izq && !raiz->der) {
		//llegue a una hoja
		if (remanente == 0) {
			return true;
		}
		return false;
	}
	else if(remanente > 0) {
		//aun no estoy en una hoja
		bool cumpleIzq =  raiz->izq && (remanente-raiz->izq->dato) >= 0 ? existeCaminoConSuma(raiz->izq, remanente) : false;
		bool cumpleDef = raiz->der && (remanente - raiz->der->dato) >= 0 ? existeCaminoConSuma(raiz->der, remanente) : false;

		return cumpleIzq || cumpleDef;
	}
	

	return false;
}

bool esArbolBalanceado(NodoAB *raiz) {
	
	if (!raiz) {
		return true;
	}
	int alturaI = altura(raiz->izq);
	int alturaD = altura(raiz->der);
	bool nodoBalanceado = alturaI - alturaD >= -1 && alturaI - alturaD <= 1;
	if (nodoBalanceado && raiz->izq && raiz->der) {
		nodoBalanceado = esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
	}
	
	return nodoBalanceado;
}

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {

	NodoLista* camino = NULL;
	if (!arbol) {
		return camino;
	}
	camino = new NodoLista;
	camino->dato = arbol->dato;

	NodoLista* aux = camino;
	while (arbol->dato != x) {
		if (x > arbol->dato) {
			arbol = arbol->der;
		}
		else {
			arbol = arbol->izq;
		}
		aux->sig = new NodoLista;
		aux->sig->dato = arbol->dato;
		aux = aux->sig;
	}

	return camino;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano).
POS: Retorna el nodo padre del nodo con el valor menor dentro del arbol.
Si el arbol recibido es vacio retorna NULL.
*/
NodoAB* preMenorNodo(NodoAB* A) {
	if (!A) {
		return NULL;
	}
	if (A->izq && A->izq->izq) {
		return preMenorNodo(A->izq);
	}

	return A;
}

/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano).
POS: Retorna el nodo padre del nodo con el valor mayor dentro del arbol.
Si el arbol recibido es vacio retorna NULL.
*/

NodoAB* preMayorNodo(NodoAB* A) {
	if (!A) {
		return NULL;
	}
	if (A->der && A->der->der) {
		return preMayorNodo(A->der);
	}

	return A;
}

void borrarNodoRaiz(NodoAB * & A) {
	
	if (!A) {
		return;
	}
	
	if (!A->izq && !A->der) {
		NodoAB* borro = A;
		A = NULL;
		delete borro;
		return;
	}
	
	NodoAB* aux = NULL;

	if (A->izq) {
		aux = preMayorNodo(A->izq);
		if (aux->der && !aux->der->izq) {
			A->dato = aux->der->dato;
			aux->der = NULL;
			delete aux->der;
		}
		else if (aux->der && aux->der->izq) {
			NodoAB* borro = aux->der->izq;
			A->dato = aux->der->dato;
			aux->der->dato = borro->dato;
			aux->der->izq = NULL;
			delete borro;
		}
		else {
			A->dato = aux->dato;
			A->izq = aux->izq;
			delete aux;
		}
	}
	else {
		aux = preMenorNodo(A->der);
		if(aux->izq){
			A->dato = aux->izq->dato;
			aux->izq = NULL;
			delete aux->izq;
		}
		else {
			A->dato = aux->dato;
			A->der = aux->der;
			delete aux;
		}
		
	}

}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (!a) {
		return -1;
	}else if (n < a->dato) {
		int izq = sucesor(a->izq, n);
		return izq < 0 ? a->dato : izq;
	}else {
		return sucesor(a->der, n);
	}
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano), 
recibe un indicador si el nivel de la raiz del arbol recibido es par o impar, recibe dos variables
acumulador par y acumulador impar.
POS: Suma los valores de los nodos de niveles pares a la variable acumuladorPares y suma los valores de los nodos
ubicados en niveles impares a la variable acumuladorImpares.
Si el arbol recibido es vacio no hace nada.
*/


void sumaNivelRec(NodoAG* raiz,bool niverPar,int & acumuladoPares,int & acumuladoImares) {
	if (!raiz) {
		return;
	}
	
	while (raiz) {
		niverPar ? acumuladoPares += raiz->dato : acumuladoImares += raiz->dato;
		if (raiz->ph) {
			sumaNivelRec(raiz->ph, !niverPar, acumuladoPares, acumuladoImares);
		}
		raiz = raiz->sh;
	}
}

int sumaPorNiveles(NodoAG* raiz){
	
	if (!raiz) {
		return 0;
	}

	int sumaPares = 0;
	int sumaImpares = 0;
	bool nivelPar = false;

	sumaNivelRec(raiz, nivelPar, sumaPares, sumaImpares);

	return sumaPares-sumaImpares;
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{

	if (!a && !l) {
		return true;
	}
	else if (a && !l) {
		return true;
	}
	else if (!a && l){
		return false;
	}
	else if (a->dato != l->dato) {
		return esPrefijo(a->sh,l);
	}
	else {
		//recursion
		return esPrefijo(a->ph, l->sig);
	}

}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	NodoLista* nodoActual = new NodoLista(arbolGeneral->dato);

	if (!arbolGeneral) {
		return NULL;
	}

	if (arbolGeneral->dato == dato) {
		 return nodoActual;
	}

	if (arbolGeneral->ph) {
		NodoLista* camino =caminoAG(arbolGeneral->ph, dato);
		if (camino) {
			nodoActual->sig = camino;
			return nodoActual;
		}
	}

	if ( arbolGeneral->sh) {
		nodoActual = caminoAG(arbolGeneral->sh, dato);
		return nodoActual;
	}
	
	return NULL;
}


/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano),
recibe tambien una lista pasada por copia.
POS: Almacena en cada posicion de la lista, el numero de nodos de cada nivel del arbol.
Ej: si el arbol en el segundo nivel tiene 3 nodos, en el segundo elemento de la lista se almacenara un 3.
*/
void cuentaNodosNivelRec(NodoAG* raiz, NodoLista*l) {
	if (!raiz) {
		return;
	}
	
	while (raiz) {
		l->dato += 1;

		if (raiz->ph) {
			if (!l->sig) {
				l->sig = new NodoLista;
			}
			cuentaNodosNivelRec(raiz->ph, l->sig);
		}
		raiz = raiz->sh;
	}
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {

	if (!arbolGeneral) {
		return 0;
	}

	NodoLista* niveles = new NodoLista;
	cuentaNodosNivelRec(arbolGeneral, niveles);

	int maximo = NULL;
	int nivelMax = 0;
	for (int i = 1; niveles; i++) {
		if (niveles->dato > maximo) {
			maximo = niveles->dato;
			nivelMax = i;
		}
		niveles = niveles->sig;
	}

	delete niveles;
	return nivelMax;
}
