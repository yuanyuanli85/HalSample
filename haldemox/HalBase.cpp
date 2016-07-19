#include "stdafx.h"
#include "HalBase.h"


HalBase::HalBase(GEN_PLATFORM genx)
{
    mGenx = genx;
}


HalBase::~HalBase()
{

}

GEN_PLATFORM HalBase::get_platfrom_id()
{
    return mGenx;
}

int HalBase::submit_command()
{
    std::cout << " error Feature Not Implemented " << std::endl;

    return CM_NOT_IMPLMENTED;
}
