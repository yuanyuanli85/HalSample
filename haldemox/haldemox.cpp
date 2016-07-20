// haldemox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HalBase.h"
#include <vector>


// create all platfrom instances and push into vector
void init(std::vector<HalBase *> &platform_vector)
{
    platform_vector.push_back(new HalGen11); // push gen11 to vector

    platform_vector.push_back(new HalGen9); // push gen9 to vector
}

template<class T>
int submit_command(HalBase *phal)
{
    T *pxhal = (T *)(phal);
    return pxhal->submit_command();
}


void test_v1()
{
    //Create instances for all supported platforms.
    //All instances are stored in a vector
    std::vector<HalBase *> platform_vector;
    init(platform_vector);

    //get the platfrom at run time
    GEN_PLATFORM running_platfrom = GEN11;

    //use platform id to get the right instance
    //invoke derived class's interface 
    for (std::vector<HalBase *>::iterator it = platform_vector.begin();
        it != platform_vector.end(); it++)
    {
        if (running_platfrom == (*it)->get_platfrom_id())
        {
            if ((*it)->get_platfrom_id() == GEN9)
            {
                submit_command<HalGen9>((*it));
            }
            if ((*it)->get_platfrom_id() == GEN11)
            {
                submit_command<HalGen11>((*it));
            }
            break;
        }
    }

    return;
}

//v2: avoid creating all platform classes at the beginning.
void init_v2(HalBase * &phal, GEN_PLATFORM running_platfrom)
{
    switch (running_platfrom)
    {
    case GEN9:
        phal = new HalGen9;
        break;

    case GEN11:
        phal = new HalGen11;
        break;
    }
    return;
}

void test_v2()
{
    //get the platfrom at run time
    GEN_PLATFORM running_platfrom = GEN11;

    //Init Class according to the running platform
    HalBase *phal = NULL;
    init_v2(phal, running_platfrom);

    //Invoke right template with running platform
    switch (running_platfrom)
    {
    case GEN9:
        submit_command<HalGen9>(phal);
        break;

    case GEN11:
        submit_command<HalGen11>(phal);
        break;
    }

    return;
}

int _tmain(int argc, _TCHAR* argv[])
{
    
    test_v2();

	return 0;
}

