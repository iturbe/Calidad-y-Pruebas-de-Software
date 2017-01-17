//
//  Header.h
//  Tarea 7
//
//  Created by Alonso Iturbe on 3/3/15.
//  Copyright (c) 2015 Alonso Iturbe. All rights reserved.
//

#ifndef Tarea_7_Header_h
#define Tarea_7_Header_h

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Encrypt {
    string cadenaOriginal;
    string cadenaEncriptada;
    string cadenaDesencriptada;
    string posibilidades[26];
    char desplazar[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
public:    
    string operator [] (int index);
    void cypher();
    void cypher(int constanteDesplazamientoParametro);
    void decrypt();
    void decrypt(int constanteDesplazamientoParametro);
    void operator () (int decryptionConstantParameter);
    friend ostream& operator << (ostream&, string &arr);
    string print(int index);
    Encrypt(string cadenaAEncriptarParametro);
    Encrypt();
    Encrypt(Encrypt& original);
};

#endif