#ifndef MOTOR_H  // Check if MYCLASS_H has not been defined
#define MOTOR_H
#include <iostream>

using namespace std;

class motor{
int id;
public:
motor(int id=1){
this->id=id;
}
void trigger(){
cout<<"Moteur ID est activé"<<endl;
}

};
#endif
