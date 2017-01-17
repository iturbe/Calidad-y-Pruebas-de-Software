//
//  main.cpp
//  Cesar Cipher
//
//  Created by Alonso Iturbe on 1/17/17.
//  Copyright © 2017 Alonso Iturbe. All rights reserved.
//

#include <iostream>
#include <string>
#include <time.h>
#include "Header.h"
#include "Cesar.h"

using namespace std;

int main() {
    
    Cesar myCesar("encriptado.txt");
    
    myCesar.decrypt("diccionario.txt");
    
    /*
    srand(time(NULL));
    
    Encrypt enigma;
    
    cout << "Ingresa tu factor de encriptación (0-26): ";
    int factor = 0;
    cin >> factor;
    
    enigma.cypher(factor); //encripta el string con el desplazamiento elegido
    enigma.decrypt(); //llena el array "posibilidades[]" con todas las opciones posibles
    enigma.decrypt(factor); //decodifica el string original con el desplazamiento elegido
    
    //impresora de variables
    cout << endl;
    cout << "Original: " << enigma.print('o') << endl;
    cout << "Encriptada: " << enigma.print('e') << endl;
    cout << "Desencriptada: " << enigma.print('d') << endl;
    
    //imprime cualquier posibilidad de desplazamiento
    //nota: para que sirva esta función, se debe de haber llamado la función decrypt()
    cout << "Encriptada con un factor de " << factor-1 << ": " << enigma.print(factor-1) << endl;
    */
    return 0;
}
