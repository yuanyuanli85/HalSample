#pragma once

typedef enum _GEN_PLATFORM_X
{
    GEN_INVALIDD = 0,
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
    HalBase(GEN_PLATFORM genx);
    ~HalBase();

    GEN_PLATFORM get_platfrom_id();
    int submit_command();

    GEN_PLATFORM mGenx;
};

class HalGen11 : public HalBase
{
public:
    HalGen11();
    ~HalGen11();
};


class HalGen9 : public HalBase
{
public:
    HalGen9();
    ~HalGen9();

    int submit_command(); // overwrite the default one.
};


