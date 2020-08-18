class espiral
{
private:
    enum direccion {derecha=1, abajo, izquierda, arriba};
    char  **  tabla;
    
    int posX;
    int posY;

    void contruccionTabla ();

    void contruirLinea (int limite, int dir);

    int tamanno;
    

public:
    espiral(int tamanno);
    char getTabla(int columna, int fila);
    
};