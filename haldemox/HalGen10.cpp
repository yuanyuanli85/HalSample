
#include "stdafx.h"
#include "HalGen10.h"



HalGen10::HalGen10()
	:mGenx(GEN10)
{

}

HalGen10::~HalGen10()
{

}

GEN_PLATFORM HalGen10::get_platfrom_id()
{
	return mGenx;
}

int HalGen10::submit_command()
{
	std::cout << " running at Gen10" << std::endl;
	return CM_SUCCESS;
}

int HalGen10::submit_x_engine()
{
	std::cout << " submit_x_engine from Gen10" << std::endl;
	return CM_SUCCESS;
}
