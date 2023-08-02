#include "abb.h"
#include <stdio.h>

typedef struct cosa {
	int clave;
	char contenido[10];
} cosa_t;

cosa_t* crear_cosa(int clave){
	cosa_t* c = (cosa_t*)malloc(sizeof(cosa_t));
	if(c)
		c->clave = clave;
	return c;
}

void destruir_cosa(cosa_t* c){
	if(c)
		free(c);
}

int comparar_cosas(void* elemento1, void* elemento2){
	if(!elemento1 || !elemento2)
		return 0;

	if(((cosa_t*)elemento1)->clave>((cosa_t*)elemento2)->clave)
		return 1;
	
	if(((cosa_t*)elemento1)->clave<((cosa_t*)elemento2)->clave)
		return -1;
	
	return 0;
}

void destructor_de_cosas(void* elemento){
	if(!elemento)
		return;
	
	destruir_cosa((cosa_t*)elemento);
}

bool mostrar_elemento(void* elemento, void* extra){
	extra=extra; //para que no se queje el compilador, gracias -Werror -Wall
	
	if(elemento)
		printf("%i ", ((cosa_t*)elemento)->clave);
	
	return false;
}

bool mostrar_hasta_5(void* elemento, void* extra){
	extra=extra; //para que no se queje el compilador, gracias -Werror -Wall
	
	if(elemento){
		printf("%i ", ((cosa_t*)elemento)->clave);
		if(((cosa_t*)elemento)->clave == 5)
			return true;
	}

	return false;
}

bool mostrar_acumulado(void* elemento, void* extra){
	if(elemento && extra){
		*(int*)extra += ((cosa_t*)elemento)->clave;
		printf("%i ", *(int*)extra);
	}

	return false;
}


int main(){
	abb_t* arbol = arbol_crear(comparar_cosas, destructor_de_cosas);

	cosa_t* c1= crear_cosa(1);
	cosa_t* c2= crear_cosa(2);
	cosa_t* c3= crear_cosa(3);
	cosa_t* c4= crear_cosa(4);
	cosa_t* c5= crear_cosa(5);
	cosa_t* c6= crear_cosa(6);
	cosa_t* c7= crear_cosa(7);
	cosa_t* auxiliar = crear_cosa(0);

	arbol_insertar(arbol, c4);
	arbol_insertar(arbol, c2);
	arbol_insertar(arbol, c6);
	arbol_insertar(arbol, c1);
	arbol_insertar(arbol, c3);
	arbol_insertar(arbol, c5);
	arbol_insertar(arbol, c7);
	
	cosa_t* elementos[10];

	printf("Recorrido preorden (deberian salir en orden 4 2 1 3 6 5 7): ");
	int cantidad = arbol_recorrido_preorden(arbol, (void**)elementos, 10);
	for(int i=0;i<cantidad;i++)
		printf("%i ", elementos[i]->clave);
	printf("\n");
	
	printf("Recorrido inorden : ");
	cantidad = arbol_recorrido_inorden(arbol, (void**)elementos, 10);
	for(int i=0;i<cantidad;i++)
		printf("%i ", elementos[i]->clave);
	printf("\n");
	
	printf("Recorrido postorden : ");
	cantidad = arbol_recorrido_postorden(arbol, (void**)elementos, 10);
	for(int i=0;i<cantidad;i++)
		printf("%i ", elementos[i]->clave);
	printf("\n");
	
	printf("Recorrido preorden iterador interno: ");    
	abb_con_cada_elemento(arbol, ABB_RECORRER_PREORDEN, mostrar_elemento, NULL);
	printf("\n");
	
	printf("Recorrido postorden hasta encontrar el 5: ");    
	abb_con_cada_elemento(arbol, ABB_RECORRER_POSTORDEN, mostrar_hasta_5, NULL);
	printf("\n");
	

	free(auxiliar);
	arbol_destruir(arbol);
	
	return 0;
}
