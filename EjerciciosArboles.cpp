#include "EjerciciosArboles.h"


int altura(NodoAB* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
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
	// IMPLEMENTAR SOLUCION
	return false;
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
	// IMPLEMENTAR SOLUCION
	return NULL;
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
