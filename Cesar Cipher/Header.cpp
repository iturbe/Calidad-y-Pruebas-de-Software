//
//  Header.cpp
//  Tarea 7
//
//  Created by Alonso Iturbe on 3/3/15.
//  Copyright (c) 2015 Alonso Iturbe. All rights reserved.
//

#include "Header.h"
#include <iostream>

using namespace std;

//funciones con sus overloads
void Encrypt::cypher(){
    int constanteDeDesplazamiento = rand() % 27;
    for (int i = 0; i < cadenaOriginal.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (cadenaOriginal[i] == desplazar[j]){
                cadenaEncriptada[i] = (desplazar[j+constanteDeDesplazamiento]);
            }
        }
    }
    //cout << cadenaEncriptada << endl;
}
void Encrypt::cypher(int constanteDesplazamientoParametro){
    int constanteDeDesplazamiento = constanteDesplazamientoParametro;
    cadenaEncriptada = cadenaOriginal;
    for (int i = 0; i < cadenaOriginal.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (cadenaOriginal[i] == desplazar[j]){
                cadenaEncriptada[i] = (desplazar[j+constanteDeDesplazamiento]);
            }
        }
    }
    //cout << cadenaEncriptada << endl;
}
void Encrypt::decrypt(){
    string temporal = cadenaOriginal;
    for (int a = 0; a < 26; a++)//las 26 posiciones del arreglo
    {
        for (int i = 0; i < cadenaOriginal.length(); i++) //recorre la cadena a desencriptar
        {
            for (int j = 0; j < 26; j++) //recorre el alfabeto
            {
                if (cadenaOriginal[i] == desplazar[j]) //match
                {
                    temporal[i] = (desplazar[j+a]);
                    posibilidades[a] = temporal;
                }
            }
        }
    }
    //cout << "sin mover: " << posibilidades[0] << "con 5: " << posibilidades[5];
}
void Encrypt::decrypt(int constanteDesplazamientoParametro){
    cadenaDesencriptada = cadenaEncriptada;
    for (int a = 0; a < cadenaEncriptada.length(); a++) //recorre la cadena encriptada
    {
        for (int b = 26; b < 52; b++) //recorre (la segunda parte) del alfabeto
        {
            if (cadenaDesencriptada[a] == desplazar[b]) {
                cadenaDesencriptada[a] = desplazar[b-constanteDesplazamientoParametro];
                break;
            }
        }
    }
    //cout << "desencriptada con 8:" << cadenaDesencriptada;
}

//overload de operadores
string Encrypt::operator [] (int index){
    return posibilidades[index];
}
ostream& operator << (ostream& os, string& arr) {
    for (int i = 0; i < arr.length(); i++) {
        os << arr[i];
    }
    return os;
}
void Encrypt::operator()(int decryptioNConstantParameter){
    cypher(decryptioNConstantParameter);
}

//impresora
string Encrypt::print(int index){
    for (int a = 0; a < 26; a++) {
        if (a == index) {
            return posibilidades[a];
        }
    }
    switch (index) {
        case 'o': //cadena a encriptar
            return cadenaOriginal;
            break;
        case 'e': //cadena encriptada
            return cadenaEncriptada;
            break;
        case 'd': //cadena desencriptada
            return cadenaDesencriptada;
            break;
            
        default:
            break;
    }
    return "algo salió mal";
}

//constructores
Encrypt::Encrypt(string cadenaAEncriptarParametro){
    cadenaOriginal = cadenaAEncriptarParametro;
}
Encrypt::Encrypt(){
    cout << "Ingresa la cadena a encriptar: ";
    cin >> cadenaOriginal;
}
Encrypt::Encrypt(Encrypt& original){
    cadenaOriginal = original.print('o');
    original.decrypt();
}