#ifndef TABBCOM_H
#define TABBCOM_H

#include "tnodoabb.h"
#include "tvectorcom.h"

class TABBCom {
private:
    TNodoABB *nodo;

    void InordenAux(TVectorCom&, int&, const TNodoABB*) const;
    void PreordenAux(TVectorCom&, int&, const TNodoABB*) const;
    void PostordenAux(TVectorCom&, int&, const TNodoABB*) const;

public:
    TABBCom();
    TABBCom(const TABBCom&);
    ~TABBCom();
    TABBCom& operator=(const TABBCom&);

    bool operator==(const TABBCom&) const;

    bool EsVacio() const;
    bool Insertar(const TComplejo&);
    bool Borrar(const TComplejo&);
    bool Buscar(const TComplejo&) const;

    TComplejo Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;

    TVectorCom Inorden() const;
    TVectorCom Preorden() const;
    TVectorCom Postorden() const;
    TVectorCom Niveles() const;
};

#endif
