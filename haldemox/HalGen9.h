#include "stdafx.h"
#include "HalBase.h"

class HalGen9 : public HalBase
{
public:
    HalGen9();
    ~HalGen9();

	GEN_PLATFORM get_platfrom_id();
    int submit_command(); 

private:
	GEN_PLATFORM mGenx;
};