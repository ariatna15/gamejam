#pragma once

using namespace System::Drawing;

class Carrito {
private:
    int x, y; // Posici�n
    int w, h; // Ancho y alto
    int dx;   // Velocidad en x

public:
    // Constructor y destructor
    Carrito(int _x, int _y, int _w, int _h, int _dx);
    ~Carrito();

    // M�todos para borrar, mover y dibujar el c�rculo
    void borrar(Graphics^ canvas);
    void mover(Graphics^ canvas);
    void dibujar(Graphics^ canvas);

    // M�todos getters
    int getX();
    int getY();
    int getW();
    int getH();
    int getDX();

    // M�todos setters
    void setX(int valor);
    void setY(int valor);
    void setW(int valor);
    void setH(int valor);
    void setDX(int valor);
};