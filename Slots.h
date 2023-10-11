#ifndef SLOT_H  // Check if MYCLASS_H has not been defined
#define SLOT_H
#include <iostream>
#include<string.h>
using namespace std;
#include"Motor.h"
class Slot{
string productName;
int Id;

int numProduits;
float prix;
motor *motor1;
motor *motor2;
public:
Slot(string nom="-",int N=0,float num=0,int id1=0,int id2=0){
productName=nom;
Id=N;
numProduits=0;
prix=num;
motor1=new motor(id1);
if(id2!=0)
motor2=new motor(id2);
}
    Slot(const Slot& other) {
        productName = other.productName;
        Id = other.Id;
        numProduits = other.numProduits;
        prix = other.prix;
        motor1 = new motor(*other.motor1);
        if (other.motor2 != nullptr) {
            motor2 = new motor(*other.motor2);
        }
    }
~Slot(){
delete motor1;
delete motor2;
}
void drop(){
motor1->trigger();
cout<<productName<<" livré à partir du logement "<<Id<<endl;
}
string getProductName (){return productName;}
void setProductName(string nom){productName=nom;}
int getNumProducts(){return numProduits;}
void setNumProducts(int num){numProduits=num;}
float getPrice(){return prix;}
void setprix(float n){prix=n;}
int getId(){return Id;}
};
#endif
