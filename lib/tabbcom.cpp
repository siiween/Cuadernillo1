#include "tabbcom.h"

// Implementación del constructor por defecto
TABBCom::TABBCom() : nodo(NULL) {}

// Implementación del constructor de copia
TABBCom::TABBCom(const TABBCom &abb) {
    if (abb.nodo != NULL) {
        nodo = new TNodoABB();
        nodo->item = abb.nodo->item;
        nodo->iz = abb.nodo->iz;
        nodo->de = abb.nodo->de;
    } else {
        nodo = NULL;
    }
}

// Implementación del destructor
TABBCom::~TABBCom() {
    if (nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}

// Implementación del operador de asignación
TABBCom &TABBCom::operator=(const TABBCom &abb) {
    if (this != &abb) {
        if (nodo != NULL) {
            delete nodo;
            nodo = NULL;
        }
        if (abb.nodo != NULL) {
            nodo = new TNodoABB();
            nodo->item = abb.nodo->item;
            nodo->iz = abb.nodo->iz;
            nodo->de = abb.nodo->de;
        }
    }
    return *this;
}

// Implementación del operador de igualdad
bool TABBCom::operator==(const TABBCom &abb) {
    return EsVacio() && abb.EsVacio() || (nodo != NULL && abb.nodo != NULL && *nodo == *abb.nodo);
}

// Implementación del método EsVacio
bool TABBCom::EsVacio() {
    return nodo == NULL;
}

// Implementación del método Insertar
bool TABBCom::Insertar(TComplejo &complejo) {
    if (Buscar(complejo)) {
        return false; // El elemento ya existe en el árbol
    }

    if (EsVacio()) {
        nodo = new TNodoABB();
        nodo->item = complejo;
        return true;
    } else {
        if (complejo.Mod() < nodo->item.Mod()) {
            return nodo->iz.Insertar(complejo);
        } else {
            return nodo->de.Insertar(complejo);
        }
    }
}

// Implementación del método Borrar
bool TABBCom::Borrar(TComplejo &complejo) {
    if (EsVacio()) {
        return false; // El árbol está vacío, no se puede borrar
    }

    if (!Buscar(complejo)) {
        return false; // El elemento no existe en el árbol, no se puede borrar
    }

    if (complejo.Mod() < nodo->item.Mod()) {
        return nodo->iz.Borrar(complejo);
    } else if (complejo.Mod() > nodo->item.Mod()) {
        return nodo->de.Borrar(complejo);
    } else {
        if (nodo->iz.EsVacio() && nodo->de.EsVacio()) {
            delete nodo;
            nodo = NULL;
        } else if (nodo->de.EsVacio()) {
            TNodoABB *aux = nodo;
            nodo = nodo->iz.nodo;
            aux->iz.nodo = NULL;
            delete aux;
        }
        else if (nodo->iz.EsVacio()) {
            TNodoABB *aux = nodo;
            nodo = nodo->de.nodo;
            aux->de.nodo = NULL;
            delete aux;
        } else {
            TNodoABB *maxIzq = nodo->iz.BuscarMax();
            nodo->item = maxIzq->item;
            nodo->iz.Borrar(maxIzq->item);
        }
        return true;
    }
}

// Implementación del método Buscar
bool TABBCom::Buscar(TComplejo &complejo) {
    if (EsVacio()) {
        return false; // El árbol está vacío, no se puede buscar
    }

    if (complejo.Mod() < nodo->item.Mod()) {
        return nodo->iz.Buscar(complejo);
    } else if (complejo.Mod() > nodo->item.Mod()) {
        return nodo->de.Buscar(complejo);
    } else {
        return true; // El elemento ha sido encontrado
    }
}

// Implementación del método BuscarMax
TNodoABB *TABBCom::BuscarMax() {
    if (EsVacio()) {
        return NULL; // El árbol está vacío, no se puede buscar el máximo
    }

    if (nodo->de.EsVacio()) {
        return nodo; // El nodo actual es el máximo
    }

    return nodo->de.BuscarMax();
}

// Implementación del método Inorden
TVectorCom TABBCom::Inorden() {
    int posicion = 1;
    TVectorCom vector(Tamaño());
    InordenAux(vector, posicion);
    return vector;
}

// Implementación del método InordenAux
void TABBCom::InordenAux(TVectorCom &vector, int &posicion) {
    if (!EsVacio()) {
        nodo->iz.InordenAux(vector, posicion);
        vector[posicion] = nodo->item;
        posicion++;
        nodo->de.InordenAux(vector, posicion);
    }
}

// Implementación del método Niveles
TVectorCom TABBCom::Niveles() {
    int posicion = 1;
    int nivel = 1;
    int maxNivel = Altura();
    TVectorCom vector(Tamaño());
    Cola<TABBCom> cola;
    cola.Encolar(*this);

    while (!cola.EsVacia()) {
        TABBCom abb = cola.Desencolar();
        vector[posicion] = abb.nodo->item;
        posicion++;

        if (abb.nodo->iz.nodo != NULL) {
            cola.Encolar(abb.nodo->iz);
        }
        if (abb.nodo->de.nodo != NULL) {
            cola.Encolar(abb.nodo->de);
        }

        nivel++;
        if (nivel > maxNivel) {
            break;
        }
    }

    return vector;
}

// Implementación del método Altura
int TABBCom::Altura() {
    if (EsVacio()) {
        return 0; // El árbol está vacío, altura 0
    }

    int alturaIzq = nodo->iz.Altura();
    int alturaDer = nodo->de.Altura();

    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}

// Implementación del método Tamaño
int TABBCom::Tamaño() {
    if (EsVacio()) {
        return 0; // El árbol está vacío, tamaño 0
    }

    return 1
       + nodo->iz.Tamaño() + nodo->de.Tamaño();
}

// Implementación del método Vaciar
void TABBCom::Vaciar() {
    if (nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}

// Implementación del método operator+
TABBCom TABBCom::operator+(const TABBCom &abb) {
    TABBCom nuevoArbol(*this);
    nuevoArbol.AgregarArbol(abb.nodo);
    return nuevoArbol;
}

// Implementación del método AgregarArbol
void TABBCom::AgregarArbol(TNodoABB *nodo) {
    if (nodo != NULL) {
        Insertar(nodo->item);
        AgregarArbol(nodo->iz.nodo);
        AgregarArbol(nodo->de.nodo);
    }
}

// Implementación del método operator-
TABBCom TABBCom::operator-(const TABBCom &abb) {
    TABBCom nuevoArbol(*this);
    nuevoArbol.QuitarArbol(abb.nodo);
    return nuevoArbol;
}

// Implementación del método QuitarArbol
void TABBCom::QuitarArbol(TNodoABB *nodo) {
    if (nodo != NULL) {
        Borrar(nodo->item);
        QuitarArbol(nodo->iz.nodo);
        QuitarArbol(nodo->de.nodo);
    }
}
