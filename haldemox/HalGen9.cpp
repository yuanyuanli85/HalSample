#include "stdafx.h"
#include "HalGen9.h"


HalGen9::HalGen9()
    :mGenx(GEN9)
{
   
}


HalGen9::~HalGen9()
{
}


int HalGen9::submit_command()
{
    std::cout << " running at Gen9" << std::endl;
    return CM_SUCCESS;
}

GEN_PLATFORM HalGen9::get_platfrom_id()
{
	return mGenx;
}