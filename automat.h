#ifndef AUTOMAT_H  // Check if MYCLASS_H has not been defined
#define AUTOMAT_H
#include <iostream>
#include<vector>

using namespace std;
#include"Slots.h"
#include"Motor.h"
class Automat{
vector<Slot*> Slots;
int cached;
int numSlot,numProductsPerSlot;
public:
Automat(int numSlot = 1, int numProductsPerSlot = 1, int c=1) {
    cached = c;
    this->numSlot = numSlot;
    this->numProductsPerSlot = numProductsPerSlot;}
    ~Automat(){
    for (Slot* slot : Slots) {
        delete slot;
    }
        }
int searchSlot(int slotID) {
    if (cached != -1 && cached->getId() == slotID) {
        return cached;
    }

    for (int i = 0; i < numSlot; i++) {
        if (Slots[i]->getId() == slotID) {
            cached = Slots[i];
            return i;
        }
    }

    return -1; // Retourne -1 si le slotID n'est pas trouvé
}

void addSlot(const string& productName, int slotID) {
    Slots.push_back(new Slot(productName, slotID));
    numSlot++;
}
void changeSlot(int slotID, string productName, int price) {
    int slotIndex = searchSlot(slotID);
    if (slotIndex != -1) {
        Slots[slotIndex]->setProductName(productName);
        Slots[slotIndex]->setprix(price);
    }
}
int getPieces(int slotID) {
    int slotIndex = searchSlot(slotID);
    if (slotIndex != -1) {
        return Slots[slotIndex]->getNumProducts();
    }
    return 0;
}
bool isAvailable(int slotID) {
    int slotIndex = searchSlot(slotID);
    if (slotIndex != -1) {
        return Slots[slotIndex]->getNumProducts() > 0;
    }
    return false;
}
void dropSlot(int slotID) {
    int slotIndex = searchSlot(slotID);
    if (slotIndex != -1) {
        Slots[slotIndex]->drop();
    }
}
void fillAll() {
    for (Slot* slot : Slots) {
        slot->setNumProducts(numProductsPerSlot);
    }
}
void refill(int slotID) {
    int slotIndex = searchSlot(slotID);
    if (slotIndex != -1) {
        Slots[slotIndex]->setNumProducts(numProductsPerSlot);
    }

}
int getNumSlots(){return this->numSlot;}
};
#endif
