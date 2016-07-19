#include "stdafx.h"
#include "HalBase.h"



HalGen9::HalGen9()
    :HalBase(GEN9)
{
   
}


HalGen9::~HalGen9()
{
}


int HalGen9::submit_command()
{
    std::cout << " running at " << mGenx << std::endl;
    return CM_SUCCESS;
}