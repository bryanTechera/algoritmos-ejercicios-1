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

void borrarNodoRaiz(NodoAB * & A) {
	// IMPLEMENTAR SOLUCION
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return 0;
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

int sumaPorNiveles(NodoAG* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
