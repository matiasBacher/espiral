#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <espiral.h>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios;


bool esDigito (const char* numero)
{   
    bool bandera= true;
    int r = 0;

    for (; numero[r]!='\000' && bandera; r++)
    {
        if (isdigit(numero[r]))
        {
            bandera=true;
        }
        else
        {
            bandera=false;
        }
        
    }
    if (r!=0 && bandera)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}



int main(int argc, const char** argv) {


    if (argc<1)
    {
        cout<<"ingrese por lo menos un valor"<<endl;
        return 2;
    }

    if (!(esDigito(argv[1])))
    {
        cout<<"Por favor ingrese un numero"<<endl;
        return 3;
    }

    const int  tamanno = atoi(argv[1]);

    if (tamanno<5)
    {
        cout <<"valor muy pequeño, tiene que se por lo menos 5"<<endl;
        return 4;
    }

    espiral miEspiral (tamanno);
    char nombreArchivo [40]="espiral";
    char extension [] = ".dat";
    if (argc>2)
    {
        strcpy(nombreArchivo, argv[2]);
    }
    
    strcat (nombreArchivo,extension);

    ofstream archivoSalida (nombreArchivo, ios::out);

    if (!archivoSalida)
    {
        cout<<"No se pudo abrir el archivo";
        return 5;    
    }
    
    for (int i = 0; i < tamanno; i++)
    {
        for (int j = 0; j < tamanno; j++)
        {
            archivoSalida<<miEspiral.getTabla(i,j)<<' ';
        }
        archivoSalida<<endl;
    }
    
    





    

    return 0;
}