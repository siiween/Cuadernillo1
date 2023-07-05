#ifndef TABBCOM_H
#define TABBCOM_H

#include "tcomplejo.h"
#include "tvectorcom.h"

class TNodoABB;

class TABBCom {
    friend class TNodoABB;
    friend ostream &operator<<(ostream &, const TABBCom &);

private:
    TNodoABB *raiz;

public:
    TABBCom();
    TABBCom(const TABBCom &);
    ~TABBCom();
    TABBCom &operator=(const TABBCom &);
    bool operator==(const TABBCom &) const;
    bool operator!=(const TABBCom &) const;
    bool EsVacio() const;
    bool Insertar(const TComplejo &);
    bool Borrar(const TComplejo &);
    bool Buscar(const TComplejo &) const;
    TComplejo Raiz() const;
    int Altura() const;
    int Nodos() const;
    int NodosHoja() const;
    TVectorCom Inorden() const;
    TVectorCom Preorden() const;
    TVectorCom Postorden() const;
    TVectorCom Niveles() const;

private:
    void Copiar(const TABBCom &);
    void BorrarNodos(TNodoABB *);
    void InordenAux(TVectorCom &, int &, TNodoABB *) const;
    void PreordenAux(TVectorCom &, int &, TNodoABB *) const;
    void PostordenAux(TVectorCom &, int &, TNodoABB *) const;
};

class TNodoABB {
    friend class TABBCom;

private:
    TComplejo item;
    TABBCom iz;
    TABBCom de;

public:
    TNodoABB();
    TNodoABB(const TNodoABB &);
    ~TNodoABB();
    TNodoABB &operator=(const TNodoABB &);
};

#endif /* TABBCOM_H */
