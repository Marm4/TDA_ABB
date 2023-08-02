#include <stdio.h>
#include <string.h>
#include "abb.h"

typedef struct club {
	int copas;
	int descensos;
	char nombre[20];
} club_t;


void destruir_club(club_t* club){
	if(club)
		free(club);
}


int comparador_descensos(void* club1, void* club2){
	if(!club1 || !club2)
		return 0;

	if(((club_t*)club1)->descensos > ((club_t*)club2)->descensos)
		return 1;
	
	if(((club_t*)club1)->descensos < ((club_t*)club2)->descensos)
		return -1;
	
	return 0;
}

void destructor(void* club){
	if(!club)
		return;
	
	destruir_club((club_t*)club);
}

club_t* crear_club(char *club, int descensos, int copas){
	club_t* crear_club = calloc(1,sizeof(club_t));
	if(!crear_club)
		return NULL;
		
	memcpy(crear_club->nombre, club, 10);
	crear_club->descensos = descensos;
	crear_club->copas = copas;
	return crear_club;
}
bool mostrar_hasta_dos(void* club, void* qcyo){
	qcyo = qcyo;
	
	if(club){
		printf(" %s(%i)", ((club_t*)club)->nombre, ((club_t*)club)->copas);
		if(((club_t*)club)->copas == 2)
			return true;
	}
	return false;
}

bool mostrar_clubes(void* club, void* qcyo){
	qcyo = qcyo;
	if(club)
		printf(" %s(%i, %i)", ((club_t*)club)->nombre, ((club_t*)club)->descensos, ((club_t*)club)->copas);
	return false;
}		

int main(){

	abb_t* clubes = arbol_crear(comparador_descensos, destructor);
	
	club_t* boca = crear_club("Boca", 0, 17);
	club_t* riber = crear_club("Riber", 1, 14);
	club_t* estudiantes = crear_club("Estudiantes", 2, 3);
	club_t* platense = crear_club("Platense", 3, 2);
	club_t* rosario_central = crear_club("Rosario_central", 4, 4);
	club_t* arg_jrs = crear_club("Arg_jrs", 5, 5);
	club_t* tigre = crear_club("Tigre", 6, 8);
	club_t* banfield = crear_club("Banfield", 7, 0);
	club_t* aux = crear_club(".", 0, 0);
	
	arbol_insertar(clubes, boca);
	arbol_insertar(clubes, riber);
	arbol_insertar(clubes, estudiantes);
	arbol_insertar(clubes, platense);
	arbol_insertar(clubes, rosario_central);
	arbol_insertar(clubes, arg_jrs);
	arbol_insertar(clubes, tigre);
	arbol_insertar(clubes, banfield);
	
	club_t* club_aux = arbol_raiz(clubes);
	printf("El club mas grande (hubicado en la raiz): %s\n", club_aux->nombre);
	
	printf("Busco un club que haya descendido una vez: ");
	aux->descensos = 1;
	club_aux = arbol_buscar(clubes, aux);
	printf("%s\n", club_aux->nombre);
	
	printf("Hay clubes guardados en el arbol?: %s\n", (arbol_vacio(clubes))==false?"SI":"NO");
	
	aux->descensos = 7;
	printf("Borro al club con mas descensos (Banfield) %s\n", (arbol_borrar(clubes, aux))==0?"Se borro con exito":"Hubo un ERROR");
	printf("\n\n");
	 
	club_t* array[10];

	printf("Muestro los clubes con mas de 5 copas (recorrido inorden): ");
	int cantidad = arbol_recorrido_inorden(clubes, (void**)array, 10);
	for(int i=0;i<cantidad;i++){
		if(array[i]->copas >= 5)
			printf(" %s(%i)", array[i]->nombre, array[i]->copas);
	}
	printf("\n");
	
	
	printf("Muestro los clubes(descensos, copas) inorden iterador interno: ");    
	abb_con_cada_elemento(clubes, ABB_RECORRER_INORDEN, mostrar_clubes, NULL);
	printf("\n"); 
	
	printf("Muestro los clubes(copas) preorden iterador interno hasta encontra a alguien con 2 copas: ");    
	abb_con_cada_elemento(clubes, ABB_RECORRER_POSTORDEN, mostrar_hasta_dos, NULL);
	printf("\n\n"); 
 	
	free(aux);
	arbol_destruir(clubes);
	
	return 0;
}
