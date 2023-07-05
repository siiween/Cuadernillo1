#ifndef _TABBCom_
#define _TABBCom_

#include "tcomplejo.h"
#include "tvectorcom.h"

class TNodoABB;
class TABBCom
{
    friend class TNodoABB;

private:
    TNodoABB *nodo;

    void Copiar(const TABBCom &abb);
    void BorrarNodos(TNodoABB *&nodo);
    TComplejo Maximo() const;

public:
    TABBCom();
    TABBCom(const TABBCom &abb);
    ~TABBCom();
    TABBCom &operator=(const TABBCom &abb);

    bool operator==(const TABBCom &abb);

    bool EsVacio();
    bool Insertar(const TComplejo &c);
    bool Borrar(const TComplejo &c);
    bool Buscar(const TComplejo &c);
    TComplejo Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;

    TVectorCom Inorden() const;
    TVectorCom Preorden() const;
    TVectorCom Postorden() const;
    TVectorCom Niveles() const;

    friend ostream &operator<<(ostream &os, const TABBCom &abb);
};

class TNodoABB
{
    friend class TABBCom;

private:
    TComplejo item;
    TABBCom iz, de;

public:
    TNodoABB();
    TNodoABB(const TNodoABB &nodo);
    ~TNodoABB();
    TNodoABB &operator=(const TNodoABB &nodo);
};
#endif
