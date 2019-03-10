//
// Created by chjz on 19-3-10.
//

#include <iostream>
#include "TLibEncoder/TEncTop.h"

int main()
{
    TComLoopFilter lf;
    lf.setCfg(1);
    std::cout << "successful!" << std::endl;
}