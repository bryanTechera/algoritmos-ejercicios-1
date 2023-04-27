#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	int i = desde;
	for (i = desde; i < hasta; i++) {
		cout << i << "*" << tablaDel << "=" << (i * tablaDel)<<";";
	}
	cout << i << "*" << tablaDel << "=" << (i * tablaDel);
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) { 
	int temporal = 0;
	int total = 0;

	for (int i = 0; i < largo; i++) {
		if (vector[i] > temporal && temporal!=0) {
			temporal++;
		}
		else if (temporal==0 && vector[i]==1) {
			temporal++;
		}
		else if (vector[i] < temporal) {
			temporal = 0;
		}
		if (temporal == 3) {
			total++;
			temporal = 0;
		}
	}
	return total;
}

int maximoNumero(unsigned int n) {
	
	int*  numeros = new int[n];
	int i = 0;
	int maximo=NULL;
	int entrada;

	for (int i = 0; i < n; i++) {
		cin >> entrada;
		if (entrada > maximo || !maximo)
			maximo = entrada;
	}
	
    return maximo;
}

void ordenarVecInt(int *vec, int largoVec) {
	int aux = 0;
	int i = 0;
	
	while (i < largoVec) {
		if (vec[i] > vec[i + 1] && (i + 1) < largoVec) {
			aux = vec[i];
			vec[i] = vec[i + 1];
			vec[i + 1] = aux;
			i --;
		}
		else {
			i++;
		}
	}
}

/*
PRE:RECIBE UN CHAR != NULL
POS: 
RETORNA 1 SI EL CHAR ES UNA LETRA EN MAYUSCULA
RETORNA 0 SI EL CHAR ES UNA LETRA EN MINUSCULA
RETORNA -1 SI EL CHAR CORRESPONDE CON UN FIN DE STRING
RETORNA -2 SI NO ES NINGUNO DE LOS CASOS ANTERIORES
*/

int obtenerCase(char x) {
	if (x >= 'A' && x <= 'Z')
		return 1;

	else if (x >= 'a' && x <= 'z')
		return 0;

	else if (x == '\0')
		return -1;
	else
		return -2;
}

/*
PRE: str!=NULL
POS: retorna el largo de la cadena str
*/

int largoString(char* str) {
	bool fueraRango = false;
	int largoVector = 0;
	while (!fueraRango) {
		if (str[largoVector] == '\0')
			fueraRango = true;
		else
			largoVector++;
	}
	largoVector++;
	return largoVector;
}

char* invertirCase(char* str)
{
	int largoVector = largoString(str);

	char* invertido = new char[largoVector];
	for (int i = 0; i< largoVector; i++) {
		char letra = str[i];
		int valorCase = obtenerCase(letra);
		if (valorCase >= 0) {
			if (valorCase == 1) {
				letra += 32;
				invertido[i] = letra;
			}
			else {
				 letra -= 32;
				invertido[i] = letra;
			}
		}
		else {
			invertido[i] = str[i];
		}
	}

	
	return invertido;
}



int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

/*
PRE:a y b DEBE NSER != NULL
POS: retorna true cuando a>b comparando codigo ASCI, en los demas caso retorna falso
*/

bool AmayorQueB(char* a, char* b) {
	bool mayor = true;
	bool iguales = true;
	int i = 0;
	while (iguales) {
		if (a[i] == '\0' && b[i] != '\0') {
			mayor = false;
			iguales = false;
		}
		else if (a[i] != b[i]) {
			iguales = false;
			if (a[i] < b[i]) {
				mayor = false;
			}
		}
		else if (a[i] == '\0' && b[i] == '\0') {
			mayor = false;
			iguales = false;
		}
		i++;
	}

	return mayor;

}

/*
PRE:ORIGINA != NULL
POS: RETORNA UN STRING IGUAL AL STRING ORIGINAL
PERO QUE NO COMPARTE MEMORIA
*/

char* clonarString(char* original) {
	int z = 0;
	int largo = largoString(original);
	char* nuevo = new char[largo];
		 while (original[z] != '\0') {
			nuevo[z] = original[z];
			z++;
		}
		 nuevo[z] = '\0';
		return nuevo;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char **vecOrdenado= new char*[largoVecStr];
	int z = 1;
	for (int x = 0; x < largoVecStr; x++) {
		char* string = *(vecStr + x);
		*(vecOrdenado + x) = clonarString(string);
	}

		for (int j = 0; j < largoVecStr - 1; j++) {
			
			char* compareA = *(vecOrdenado + j);
			char* compareB = *(vecOrdenado + j + 1);

			bool cambio = AmayorQueB(compareA, compareB);
			
			if (cambio) {
				vecOrdenado[j] = compareB;
				 vecOrdenado[j + 1] = compareA;
				 (j>0)?j-=2:j=-1;
			}
	}
    return vecOrdenado;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	
	if (l1 + l2 == 0) return NULL;

	int* intercalado = new int[l1 + l2];
	
	int iA = 0;
	int iB = 0;
	while (iA< l1 || iB<l2) {
		int i = iA + iB;
		int valueA = iA < l1 ? v1[iA] : NULL;
		int valueB = iB < l2 ? v2[iB] : NULL;

		if ((valueA < valueB && iA < l1) || iB == l2) {
			intercalado[i] = valueA;
			iA++;
		}
		else if ((valueA > valueB && iB < l2) || iA == l1) {
			intercalado[i] = valueB;
			iB++;
		}
		else if(iA < l1 && iB < l2){
			intercalado[i] = valueA;
			iA++;
			i= iA + iB;
			intercalado[i] = valueB;
			iB++;
		}
	}



	return intercalado;
}


bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	if (l1==0) {
		return true;
	}
	else if (l2 == 0) {
		return false;
	}
	else {
		bool esSubconjunto = true;
		for (int i = 0; i < l1 && esSubconjunto; i++) {
			bool encontrado = false;
			int elem = v1[i];
			for (int e = 0; e < l2 && !encontrado; e++) {
				if (elem == v2[e]) encontrado = true;
			}
			if (!encontrado) esSubconjunto = false;
		}
		return esSubconjunto;
		
	}
	

}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
