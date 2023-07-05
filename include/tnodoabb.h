#ifndef TNODOABB_H
#define TNODOABB_H

#include "tcomplejo.h"

class TABBCom;

class TNodoABB {
    friend class TABBCom;
private:
    TComplejo item;
    TNodoABB *izquierdo;
    TNodoABB *derecho;

public:
    TNodoABB();
    TNodoABB(const TComplejo& com);
    ~TNodoABB();
};

#endif
