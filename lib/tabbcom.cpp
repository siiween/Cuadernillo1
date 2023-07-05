#include "tabbcom.h"

TABBCom::TABBCom() : nodo(nullptr) {}

TABBCom::TABBCom(const TABBCom& abb) : nodo(nullptr) {
    if (abb.nodo != nullptr) {
        nodo = new TNodoABB(*abb.nodo);
    }
}

TABBCom::~TABBCom() {
    delete nodo;
}

TABBCom& TABBCom::operator=(const TABBCom& abb) {
    if (this != &abb) {
        delete nodo;
        if (abb.nodo != nullptr) {
            nodo = new TNodoABB(*abb.nodo);
        }
    }
    return *this;
}

bool TABBCom::operator==(const TABBCom& abb) const {
    if (nodo == nullptr && abb.nodo == nullptr)
        return true;
    if (nodo == nullptr || abb.nodo == nullptr)
        return false;

    return (nodo == abb.nodo);
}


bool TABBCom::EsVacio() const {
    return (nodo == nullptr);
}
