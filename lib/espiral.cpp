#include <espiral.h>

espiral::espiral (int tamanno)
{   
    this->posX=0;
    this->posY=0;

    this->tamanno=tamanno;

    this->tabla = new char * [tamanno];
    for (int i = 0; i < tamanno; i++)
    {
        this->tabla[i]=new char[tamanno];
        for (int j = 0; j < tamanno; j++)
        {
            this->tabla[i][j]=' ';
        }
        
    }
    
    this->contruccionTabla();
}

void espiral::contruirLinea (int limites, int dir)
{
    int valorX= this->posX;
    int valorY= this->posY;

    int sumado = (dir<3)?1:-1;

    int * varPtr = (dir%2==0)?&valorY:&valorX;

    for (int conteo = 0; conteo < limites; conteo++)
    {
        this->tabla[valorY][valorX]='x';
        *varPtr+=sumado;
    }
    *varPtr-=sumado;
    this->posX=valorX;
    this->posY=valorY;
}

void espiral::contruccionTabla()
{
    int dir=derecha;
    int limite=this->tamanno;

    int comutador=-1;

    while (limite>3)
    {
        if (dir>4)
        {
            dir=derecha;
        }
        if (comutador>1)
        {
            limite-=2;
            comutador=0;
        }
        contruirLinea (limite, dir);
        dir++;
        comutador++;
        
    }
    
    
}

char  espiral::getTabla(int columna, int fila)
{
    return this->tabla[columna][fila];
}