#include "stdafx.h"
#include "HalBase.h"

class HalGen11 : public HalBase 
{
public:
	HalGen11();
	~HalGen11();

	GEN_PLATFORM get_platfrom_id();
	int submit_command();
    int submit_x_engine();

private:
	GEN_PLATFORM mGenx;
};