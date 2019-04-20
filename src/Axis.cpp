#include <Axis.h>

Axis::Axis(int plusPin, int minusPin):
    plusPin(plusPin), minusPin(minusPin){
        setup();
    }

Axis::~Axis(){
    reset();
}

void Axis::setup(){
    pinMode(this->plusPin, OUTPUT);
    pinMode(this->minusPin, OUTPUT);
}

void Axis::minus(){
    digitalWrite(this->minusPin, HIGH);
    digitalWrite(this->plusPin, LOW);
}

void Axis::plus(){
    digitalWrite(this->minusPin, LOW);
    digitalWrite(this->plusPin, HIGH);
}

void Axis::reset(){
    digitalWrite(this->minusPin, LOW);
    digitalWrite(this->plusPin, LOW);
}