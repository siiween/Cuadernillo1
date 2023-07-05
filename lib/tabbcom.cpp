#include "tabbcom.h"

// Implementación de la clase TNodoABB

TNodoABB::TNodoABB() : iz(), de() {}

TNodoABB::TNodoABB(const TNodoABB &nodo) : item(nodo.item), iz(nodo.iz), de(nodo.de) {}

TNodoABB::~TNodoABB() {}

TNodoABB &TNodoABB::operator=(const TNodoABB &nodo)
{
    if (this != &nodo)
    {
        item = nodo.item;
        iz = nodo.iz;
        de = nodo.de;
    }
    return *this;
}

// Implementación de la clase TABBCom

TABBCom::TABBCom() : nodo(NULL) {}

TABBCom::TABBCom(const TABBCom &abb)
{
    Copiar(abb);
}

TABBCom::~TABBCom()
{
    BorrarNodos(nodo);
}

TABBCom &TABBCom::operator=(const TABBCom &abb)
{
    if (this != &abb)
    {
        BorrarNodos(nodo);
        Copiar(abb);
    }
    return *this;
}

bool TABBCom::operator==(const TABBCom &abb)
{
    return (*nodo == *abb.nodo);
}

bool TABBCom::EsVacio()
{
    return (nodo == NULL);
}

bool TABBCom::Insertar(const TComplejo &c)
{
    if (Buscar(c))
        return false;
    if (EsVacio())
    {
        nodo = new TNodoABB();
        nodo->item = c;
        return true;
    }
    else if (c.Mod() < nodo->item.Mod())
        return nodo->iz.Insertar(c);
    else
        return nodo->de.Insertar(c);
}

bool TABBCom::Borrar(const TComplejo &c)
{
    if (EsVacio())
        return false;
    else if (c.Mod() < nodo->item.Mod())
        return nodo->iz.Borrar(c);
    else if (c.Mod() > nodo->item.Mod())
        return nodo->de.Borrar(c);
    else
    {
        if (nodo->iz.EsVacio() && nodo->de.EsVacio())
        {
            delete nodo;
            nodo = NULL;
        }
        else if (nodo->iz.EsVacio())
        {
            TNodoABB *aux = nodo;
            nodo = nodo->de.nodo;
            aux->de.nodo = NULL;
            delete aux;
        }
        else if (nodo->de.EsVacio())
        {
            TNodoABB *aux = nodo;
            nodo = nodo->iz.nodo;
            aux->iz.nodo = NULL;
            delete aux;
        }
        else
        {
            TNodoABB *maxIzq = nodo->iz.Maximo();
            nodo->item = maxIzq->item;
            nodo->iz.Borrar(maxIzq->item);
        }
        return true;
    }
}

bool TABBCom::Buscar(const TComplejo &c)
{
    if (EsVacio())
        return false;
    else if (c.Mod() < nodo->item.Mod())
        return nodo->iz.Buscar(c);
    else if (c.Mod() > nodo->item.Mod())
        return nodo->de.Buscar(c);
    else
        return true;
}

TComplejo TABBCom::Raiz() const
{
    if (EsVacio())
        return TComplejo();
    return nodo->item;
}

int TABBCom::Altura() const
{
    if (EsVacio())
        return 0;
    int alturaIzq = nodo->iz.Altura();
    int alturaDer = nodo->de.Altura();
    return 1 + ((alturaIzq > alturaDer) ? alturaIzq : alturaDer);
}

int TABBCom::Nodos() const
{
    if (EsVacio())
        return 0;
    return 1 + nodo->iz.Nodos() + nodo->de.Nodos();
}

int TABBCom::NodosHoja() const
{
    if (EsVacio())
        return 0;
    if (nodo->iz.EsVacio() && nodo->de.EsVacio())
        return 1;
    return nodo->iz.NodosHoja() + nodo->de.NodosHoja();
}

TVectorCom TABBCom::Inorden() const
{
    int pos = 1;
    TVectorCom v(Nodos());
    InordenAux(v, pos);
    return v;
}

void TABBCom::InordenAux(TVectorCom &v, int &pos) const
{
    if (!EsVacio())
    {
        nodo->iz.InordenAux(v, pos);
        v[pos] = nodo->item;
        pos++;
        nodo->de.InordenAux(v, pos);
    }
}

TVectorCom TABBCom::Preorden() const
{
    int pos = 1;
    TVectorCom v(Nodos());
    PreordenAux(v, pos);
    return v;
}

void TABBCom::PreordenAux(TVectorCom &v, int &pos) const
{
    if (!EsVacio())
    {
        v[pos] = nodo->item;
        pos++;
        nodo->iz.PreordenAux(v, pos);
        nodo->de.PreordenAux(v, pos);
    }
}

TVectorCom TABBCom::Postorden() const
{
    int pos = 1;
    TVectorCom v(Nodos());
    PostordenAux(v, pos);
    return v;
}

void TABBCom::PostordenAux(TVectorCom &v, int &pos) const
{
    if (!EsVacio())
    {
        nodo->iz.PostordenAux(v, pos);
        nodo->de.PostordenAux(v, pos);
        v[pos] = nodo->item;
        pos++;
    }
}

TVectorCom TABBCom::Niveles() const
{
    TVectorCom v(Nodos());
    if (!EsVacio())
    {
        TColaCom cola;
        int pos = 1;
        TNodoABB *nodoActual;
        cola.Encolar(Raiz());
        while (!cola.EsVacia())
        {
            cola.Primero().MostrarComplejo();
            v[pos] = cola.Primero();
            pos++;
            nodoActual = nodo->iz.nodo;
            if (!nodoActual->iz.EsVacio())
                cola.Encolar(nodoActual->iz.nodo->item);
            if (!nodoActual->de.EsVacio())
                cola.Encolar(nodoActual->de.nodo->item);
            cola.Desencolar();
        }
    }
    return v;
}

ostream &operator<<(ostream &os, const TABBCom &abb)
{
    os << abb.Inorden();
    return os;
}

void TABBCom::Copiar(const TABBCom &abb)
{
    if (abb.nodo == NULL)
        nodo = NULL;
    else
    {
        nodo = new TNodoABB();
        nodo->item = abb.nodo->item;
        nodo->iz.Copiar(abb.nodo->iz);
        nodo->de.Copiar(abb.nodo->de);
    }
}

void TABBCom::BorrarNodos(TNodoABB *&nodo)
{
    if (nodo != NULL)
    {
        BorrarNodos(nodo->iz.nodo);
        BorrarNodos(nodo->de.nodo);
        delete nodo;
        nodo = NULL;
    }
}

TComplejo TABBCom::Maximo() const
{
    if (!EsVacio())
    {
        TNodoABB *aux = nodo;
        while (!aux->de.EsVacio())
        {
            aux = aux->de.nodo;
        }
        return aux->item;
    }
    return TComplejo();
}
