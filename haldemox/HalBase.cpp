#include "stdafx.h"
#include "HalBase.h"


HalBase::HalBase()
{

}


HalBase::~HalBase()
{

}

int HalBase::load_kernel_binary()
{
	std::cout << " call load kernel binary from HalBase " << std::endl;

	return CM_SUCCESS;
}

GEN_PLATFORM HalBase::get_platfrom_id()
{
	return GEN_INVALIDE;
}

int HalBase::submit_command()
{
    std::cout << " error Feature Not Implemented " << std::endl;

    return CM_NOT_IMPLMENTED;
}

int HalBase::submit_x_engine()
{
	std::cout << " error submit_x_engine not implemented " << std::endl;

	return CM_NOT_IMPLMENTED;
}
