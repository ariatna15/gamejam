#include "Carrito.h"

// Constructor
Carrito::Carrito(int _x, int _y, int _w, int _h, int _dx) {
    this->x = _x;
    this->y = _y;
    this->w = _w;
    this->h = _h;
    this->dx = _dx;
}

// Destructor
Carrito::~Carrito() {}

// Método para borrar el círculo
void Carrito::borrar(Graphics^ canvas) {
    // Borra el cuerpo del auto
    canvas->FillRectangle(Brushes::White, x, y+21, w+5, h-30);
    // Dibuja el techo en forma de trapecio
    array<Point>^ puntosTecho = {
        Point(x + 50, y + 20),        // Punto inferior derecho
        Point(x , y + 20),             // Punto inferior izquierdo
        Point(x +10, y),                 // Punto superior izquierdo
        Point(x + 40, y),             // Punto superior derecho
    };
    canvas->FillPolygon(Brushes::White, puntosTecho);
   
    // Borra las ruedas
    canvas->FillEllipse(Brushes::White, x + 5, y + 30, 20, 20);
    canvas->FillEllipse(Brushes::White, x + w - 20, y + 30, 20, 20);


}

// Método para mover el círculo
void Carrito::mover(Graphics^ canvas) {
    if (x < 0 || x + w > canvas->VisibleClipBounds.Width) dx *= -1; // Cambia dirección si toca los bordes
    x += dx; // Actualiza la posición
}

// Método para dibujar el círculo
void Carrito::dibujar(Graphics^ canvas) {
    // Dibuja el cuerpo del auto
    canvas->FillRectangle(Brushes::Black, x, y+21, w+5, h-30);
    // Dibuja el techo en forma de trapecio
    array<Point>^ puntosTecho = {
        Point(x + 50, y + 20),        // Punto inferior derecho
        Point(x , y + 20),             // Punto inferior izquierdo
        Point(x + 10, y),                 // Punto superior izquierdo
        Point(x + 40, y),             // Punto superior derecho
    };
    canvas->FillPolygon(Brushes::Black, puntosTecho);
    canvas->DrawLine(Pens::White, x, y + h / 2, x + w, y + h / 2);
    canvas->DrawLine(Pens::White, x + w / 2, y+5, x + w / 2, y + h);
    canvas->DrawLine(Pens::White, x + w / 10, y + 5, x + w / 10, y + h);
    canvas->DrawLine(Pens::White, x + w / 4, y + 5, x + w / 4, y + h);
    canvas->DrawLine(Pens::White, x + w , y + 5, x + w / 2, y + h);
    // Dibuja las ruedas blanca grande
    canvas->FillEllipse(Brushes::White, x + 3, y + 29, 23, 23);
    canvas->FillEllipse(Brushes::White, x + w - 22, y + 29, 23, 23);
    // Dibuja las ruedas
    canvas->FillEllipse(Brushes::Black, x + 5, y+30 , 20, 20);
    canvas->FillEllipse(Brushes::Black, x + w - 20, y +30, 20, 20);
    // Dibuja las ruedas blanca
    canvas->FillEllipse(Brushes::White, x + 10, y + 35, 10, 10);
    canvas->FillEllipse(Brushes::White, x + w - 15, y + 35, 10, 10);
    //// Dibuja las ventanas
    canvas->FillRectangle(Brushes::White, x + 15, y + 4, (w / 2) - 13, 16);
    canvas->FillRectangle(Brushes::White, x + (w / 2) + 5, y + 4, (w / 2) - 15, 16);
}

// Getters
int Carrito::getX() {
    return this->x;
}
int Carrito::getY() {
    return this->y;
}
int Carrito::getW() {
    return this->w;
}
int Carrito::getH() {
    return this->h;
}
int Carrito::getDX() {
    return this->dx;
}

// Setters
void Carrito::setX(int valor) {
    this->x = valor;
}
void Carrito::setY(int valor) {
    this->y = valor;
}
void Carrito::setW(int valor) {
    this->w = valor;
}
void Carrito::setH(int valor) {
    this->h = valor;
}
void Carrito::setDX(int valor) {
    this->dx = valor;
}
