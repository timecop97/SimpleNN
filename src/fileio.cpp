#include <iostream>
#include <fstream>
#include <stdio.h>
#include "fileio.h"
using namespace std;



int getNextPixel(){
    char dummy[8];
    uint8_t a;
    static ifstream imagesFile("images.ff", ios::in | ios::binary);
    if(!imagesFile){
        printf("image file is fucked");
    }
    if(imagesFile.gcount() == 0){
        printf("image file stream not init'd. lets do that\n");
        imagesFile.read(dummy, 8);
        imagesFile.read(dummy, 8);
    }
    imagesFile.read((char*)&a, 1);
    return((int)a);
}

int getNextLabel(){
    char dummy[8];
    uint8_t a;
    static ifstream labelsFile("labels.ff", ios::in | ios::binary);
    if(!labelsFile){
        printf("label file is fucked");
    }
    if(labelsFile.gcount() == 0){
        printf("labels file stream not init'd. lets do that\n");
        labelsFile.read(dummy, 8);
    }
    labelsFile.read((char*)&a, 1);
    return((int)a);
}
