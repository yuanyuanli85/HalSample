#include "stdafx.h"
#include "HalBase.h"

class HalGen10 : public HalBase
{
public:
	HalGen10();
	~HalGen10();

	GEN_PLATFORM get_platfrom_id();
	int submit_command();
	int submit_x_engine();

private:
	GEN_PLATFORM mGenx;
};