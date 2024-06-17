#include "Handler.h"

short Handler::currentWindow = WINDOW_HOME;

Handler::Handler(){
    // Constructor
}

void Handler::setFucnctions(HandleOp upFunc, HandleOp downFunc, HandleOp selectFunc, HandleOp backFunc){
    // Static function to set all functions
    set_UpFunc(upFunc);
    set_DownFunc(downFunc);
    set_SelectFunc(selectFunc);
    set_BackFunc(backFunc);
}

void Handler::Up(){
    upFunc();
}

void Handler::set_UpFunc(HandleOp uf){
    upFunc = *uf;
}

void Handler::Down(){
    downFunc();
}

void Handler::set_DownFunc(HandleOp df){
    downFunc = *df;
}

void Handler::Select(){
    selectFunc();
}

void Handler::set_SelectFunc(HandleOp sf){
    selectFunc = *sf;
}

void Handler::Back(){
    backFunc();
}

void Handler::set_BackFunc(HandleOp bf){
    backFunc = *bf;
}


