#include <St4.h>

St4::St4(Axis ra, Axis dec):
ra(ra), dec(dec){
    OK = "OK#";
    KO = "KO#";
}

St4::~St4(){
    ra.reset();
    dec.reset();    
}

void St4::reset(){
    ra.reset();
    dec.reset();
}

void St4::setup(){
    ra.setup();
    dec.setup();
}
String St4::process(String opcode){
    //Parse opcode
    if(opcode=="CONNECT"){
      reset();
    }
    else if (opcode=="DISCONNECT"){
      reset();
    }
    else if(opcode=="RA0"){
      ra.reset();
    }
    else if(opcode=="RA+"){
      ra.plus();
    }
    else if(opcode=="RA-"){
      ra.minus();
    }
    else if(opcode=="DEC0"){
      dec.reset();
    }
    else if(opcode=="DEC+"){
      dec.plus();
    }
    else if(opcode=="DEC-"){
      dec.minus();
    }
    else{
      return KO;
    }
    return OK ;
}