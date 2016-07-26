#include "stdafx.h"
#include "HalBase.h"

HalGen11::HalGen11()
:mGenx(GEN11)
{
}


HalGen11::~HalGen11()
{
}


GEN_PLATFORM HalGen11::get_platfrom_id()
{
	return mGenx;
}

int HalGen11::submit_command()
{
	std::cout << " running at Gen11" << std::endl;
	return CM_SUCCESS;
}


int HalGen11::submit_x_engine()
{
	std::cout << " submit_x_engine running at Gen11" << std::endl;
	return CM_SUCCESS;
}



