#include "tnodoabb.h"

TNodoABB::TNodoABB() : item(), izquierdo(nullptr), derecho(nullptr) {}

TNodoABB::TNodoABB(const TComplejo& com) : item(com), izquierdo(nullptr), derecho(nullptr) {}

TNodoABB::~TNodoABB() {
    delete izquierdo;
    delete derecho;
}
