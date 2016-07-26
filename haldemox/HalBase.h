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
