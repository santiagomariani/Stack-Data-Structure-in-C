#include "pila.h"
#include "testing.h"
#include <stddef.h>

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_vacia();
void prueba_pila_apilar();
void prueba_pila_desapilar();
void prueba_pila_vertope();
void prueba_pila_redimensionar();

void prueba_pila_vacia(){
	pila_t* pila = pila_crear();
	print_test("Se crea una pila vacia",pila_esta_vacia(pila));

	void* aux = NULL;
	pila_apilar(pila,aux);
	pila_desapilar(pila);

	print_test("Apilo y desapilo (la pila debe seguir siendo vacia)",pila_esta_vacia(pila));
	pila_destruir(pila);
}

void prueba_pila_apilar(){
	pila_t* pila = pila_crear();
	void* aux = NULL;
	pila_apilar(pila,aux);
	print_test("Se apilo un valor, la pila no esta vacia",!pila_esta_vacia(pila));	
	pila_desapilar(pila);

	for(int i=0;i<10;i++){
		pila_apilar(pila,aux);
		pila_desapilar(pila);
	}
	print_test("Se prueba apilar/desapilar consecutivo",pila_esta_vacia(pila));

	pila_destruir(pila);
}

void prueba_pila_desapilar(){
	pila_t* pila = pila_crear();
	print_test("No se puede desapilar una pila vacia",pila_desapilar(pila) == NULL);
	void* aux = NULL;
	pila_apilar(pila,aux);
	print_test("Se desapila un valor, la pila debe devolver este valor",pila_desapilar(pila) == NULL);
	print_test("La pila esta vacia",pila_esta_vacia(pila));

	for(int i=0;i<3;i++){
		pila_apilar(pila,aux);
	}
	for(int i=0;i<3;i++){
		pila_desapilar(pila);
	}
	print_test("Se desapila la pila hasta estar vacia. La pila esta vacia ",pila_esta_vacia(pila));
	pila_destruir(pila);
}

void prueba_pila_vertope(){
	pila_t* pila = pila_crear();
	void* aux = NULL;
	print_test("Ver tope: Si la pila esta vacia, devuelve NULL",pila_ver_tope(pila) == NULL);
	pila_apilar(pila,aux);
	print_test("Apilo, miro el tope y debe ser el valor que apile",!pila_esta_vacia(pila) && pila_ver_tope(pila) == NULL);
	pila_destruir(pila);
}

void prueba_pila_redimensionar(){
	pila_t* pila = pila_crear();
	void* aux = NULL;
	
	for(int i=0;i<11;i++){
		pila_apilar(pila,aux);
	}
	for(int i=0;i<11;i++){
		pila_desapilar(pila);
	}
	
	print_test("Se prueba que la redimension funciona correctamente", pila_esta_vacia(pila));
	pila_destruir(pila);
}

void pruebas_pila_alumno() {
   
    prueba_pila_vacia();
	prueba_pila_apilar();
	prueba_pila_desapilar();
	prueba_pila_vertope();
	prueba_pila_redimensionar();
}

// //////////////////////////////

