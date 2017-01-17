//
//  Cesar.h
//  Cesar Cipher
//
//  Created by Alonso Iturbe on 1/17/17.
//  Copyright © 2017 Alonso Iturbe. All rights reserved.
//

#ifndef Cesar_h
#define Cesar_h

#include <string.h>
#include <iostream>
#include <fstream>

class Cesar {
    string line;
    char desplazar[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string posibilidades[26];
    
public:
    Cesar(string file){
        ifstream myFile(file);
        if (myFile.is_open()){
            getline(myFile, line);
            cout << line << '\n';
            /*
            while (getline(myFile, line)){
                cout << line << '\n';
            }
             */
            myFile.close();
        }
        else cout << "Unable to open file";
    }
    
    void createPosibilities(){
        string temporal = line;
        for (int a = 0; a < 26; a++)//las 26 posiciones del arreglo
        {
            for (int i = 0; i < line.length(); i++) //recorre la cadena a desencriptar
            {
                for (int j = 0; j < 26; j++) //recorre el alfabeto
                {
                    if (line[i] == desplazar[j]) //match
                    {
                        temporal[i] = (desplazar[j+a]);
                        posibilidades[a] = temporal;
                    }
                }
            }
        }
    }
    
    //encuentra si existe en el diccionario
    void decrypt(string dictionaryFile){
        ifstream myDictionary(dictionaryFile);
        string tempDictionaryLine;
        if (myDictionary.is_open()){
            string temporal = line;
            
            createPosibilities();
            
            while (getline(myDictionary, tempDictionaryLine)){ //por cada línea del diccionario...
                for (int a = 0; a < 26; a++){ // checar si hay un match dentro de posibilidades[]
                    //cout << "comparando " << tempDictionaryLine << " vs. " << posibilidades[a] << endl;
                    if (strcicmp(tempDictionaryLine.c_str(), posibilidades[a].c_str()) == 0){
                        cout << "Match: " << tempDictionaryLine << " = " << posibilidades[a] << endl;
                    }
                }
            }
        }
    }
    
    string operator [] (int index){
        return posibilidades[index];
    }
    
    //case-insensitive string compare jalado de stackoverflow papu
    int strcicmp(char const *a, char const *b)
    {
        for (;; a++, b++) {
            int d = tolower(*a) - tolower(*b);
            if (d != 0 || !*a)
                return d;
        }
    }
};


#endif /* Cesar_h */
