Tda ABB - Algoritmos y programacion II - Catedra Mendez
Nombre: Marco Masciulli, Padron: 105145, Dni: 39804927

Arbol_crear: Reserva la memoria para comenzar a utilizar el abb. Contiene un puntero al primer elemento del arbol.

Arbol_insertar: Utilice la funcion "insertar_nodo", el cual recibe como parametros el arbol (Para utilizar el comparador),
	Un nodo raiz (para saber si llegue al lugar de incersion), un nodo padre y un dato entero "es_derecha" (Es derecha me sirve para saber
	si tengo que insertar en el padre a la derecha, o en el padre a la izquierda. En caso de ser 0, se inserta a la izquierda, si es 1 a la
	derecha) y el elemento a insertar (el cual se inserta mediante la funcion "crear_nodo").

Borrar_elemento: Para borrar el elemento, cree la funcion "Destruir_nodo". En esta funcion, mi implementacion no es la mejora, ya que no lo
	hago recursivo, pero fue la mejor manera que encontre para que me funcione. Esta funcion recibe como parametros el arbol, el nodo a eliminar
	llamado "raiz" y el padre del mismo nodo.
	
arbol_buscar: Utilizo la funcion "buscar_elemento". Recibe como parametros el arbol, un nodo (El cual sera devuelto, llamado raiz), y el elemento 	buscado. La funcion se llama recursivamente a si misma, comparando (con el comparador del arbol) el elemento buscado con el nodo raiz, 
	 hasta encontrar el elemento. Devuelve el elemento, en caso contrario, devuelve NULL.

arbol_raiz: Devuelve la raiz. Dado que el arbol ya contiene un puntero a la raiz, simplemente devuelvo ese puntero.

Recorridos (inOrden, preOrden, postOrden): En los tres casos utilizo una funcion auxiliar, las cuales recibe los mismos parametros que la funcion 	que la invoca (arbol_recorrido_***orden(abb_t* arbol, void** array, int tamanio_array)). Se llaman recursivamente a si mismas, en el orden
	pedido. Una vez llegado al momento de almacenar, se pregunta si hay espacio. Si hay guarda el elemento en el array, de lo contrario 		continua hasta devolver
	
arbol_destruir: Destruye la memoria almacenada para el arbol. Si contiene nodos, llama a la funcion destruir_arbol el cual destruye los nodos del 	arbol.

abb_con_cada_elemento: Invoca a la funciones "imprimir (inOrden, postOrden, preOrden)" segun manden por parametros. El funcionamiento de estas 		funciones es similar al de los recorridos, a diferencia de que no almacena los datos, sino que los imprime. Se llaman a si mismas 		recursivamente. 

Que es un arbol binario?: Un arbol binario es una estructura la cual contiene un nodo raiz. Este nodo raiz, tiene 2 hijos, y solamente dos hijos 		(2punteros a otros dos nodos). Y estos dos nodos, pueden a su vez teneer dos hijos cada uno, y asi sucesivamente. Eso es lo que 			caracterisa al arbol binario, como maximo puede tener 2 hijos.

Y un arbol binario de busqueda?: El concepto es el mismo que el arbol binario. Lo que lo diferencia es que es, si o si, al momento de insertar un 	nodo (y segun la implementacion que tomemos, en este caso, menor a la izq, mayor o igual a la derecha), si el elemento es menor al padre, 	debe de insertarse a la izquierda. Y si es mayor, a la derecha.

complejidad: En su gran mayoria, la complejidad es O(logn). Los recorridos, dado que se recorren todos los elementos es O(n) al igual que al 		momento de destruir el arbol. Por otra para al insertar o borrar un elemento es O(logn).
