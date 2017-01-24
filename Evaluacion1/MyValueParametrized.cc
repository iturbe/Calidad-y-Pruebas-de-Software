#include "Ordenamiento.h"
#include "gtest/gtest.h"
#include <iostream>

#define ARRAY_SIZE 5

using namespace std;

class OrdenamientoFixture : public ::testing::Test{
public:
	static Ordenamiento <int> *a;
	int arreglo[5];
	
	//primero se ejecuta TestCaseSetUp globalmente
	static void SetUpTestCase(){
		a = new Ordenamiento<int>();	
	}
	
	//luego setup y teardown por cada prueba
	void SetUp(){
		arreglo[0] = 9;
		arreglo[1] = 1;
		arreglo[2] = 5;
		arreglo[3] = 3;
		arreglo[4] = 7;
	}

	void TearDown(){
		//a->clear();
	}

	//TestCaseTearDown se manda llamar hasta que acaban todas las pruebas
	static void TearDownTestCase(){
		delete a;
		//delete arreglo[];
	}
};

Ordenamiento <int> * OrdenamientoFixture::a = 0;

TEST_F(OrdenamientoFixture, Bubble_Asc){
	a->burbuja(arreglo, 5, a->asc);
	for (int a = 0; a < ARRAY_SIZE-1; a++){
		EXPECT_LE(arreglo[a], arreglo[a+1]);
	}
}

TEST_F(OrdenamientoFixture, Insertion_Asc){
	a->insercion(arreglo, 5, a->asc);
	for (int a = 0; a < ARRAY_SIZE-1; a++){
		EXPECT_LE(arreglo[a], arreglo[a+1]);
	}
}

TEST_F(OrdenamientoFixture, Selection_Asc){
	a->seleccion(arreglo, 5, a->asc);
	for (int a = 0; a < ARRAY_SIZE-1; a++){
		EXPECT_LE(arreglo[a], arreglo[a+1]);
	}
}

TEST_F(OrdenamientoFixture, Quicksort_Asc){
	a->quicksort(arreglo, 0, 4, a->asc);
	for (int a = 0; a < ARRAY_SIZE-1; a++){
		EXPECT_LE(arreglo[a], arreglo[a+1]);
	}
}

TEST_F(OrdenamientoFixture, Mergesort_Asc){
	a->mergesort(arreglo, 0, 4, a->asc, 5);
	for (int a = 0; a < ARRAY_SIZE-1; a++){
		EXPECT_LE(arreglo[a], arreglo[a+1]);
	}
}