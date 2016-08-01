#pragma once

typedef enum _GEN_PLATFORM_X
{
    GEN_INVALIDE = 0,
    GEN8,
    GEN9,
    GEN10,
    GEN11
}GEN_PLATFORM, *PGEN_PLATFORM;

#define CM_NOT_IMPLMENTED -99
#define CM_SUCCESS         0

class HalBase
{
public:
    HalBase();
    ~HalBase();

	int load_kernel_binary();
    virtual GEN_PLATFORM get_platfrom_id();
    virtual int submit_command();
	virtual int submit_x_engine();


};

