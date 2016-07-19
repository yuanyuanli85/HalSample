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

int _tmain(int argc, _TCHAR* argv[])
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

	return 0;
}

