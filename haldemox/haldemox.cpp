// haldemox.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HalBase.h"
#include <vector>
#include "HalInit.h"



int c_interface_submit_x_engine(HalBase *phal)
{
    return phal->submit_x_engine();
}




void test_v2(GEN_PLATFORM running_platfrom)
{

	//Init Class according to the running platform
	HalBase *phal = NULL;
	init(phal, running_platfrom);

	std::cout << "platform is " << phal->get_platfrom_id() << std::endl;

	phal->load_kernel_binary();

	phal->submit_command();

	c_interface_submit_x_engine(phal);

	return;
}


int _tmain(int argc, _TCHAR* argv[])
{
    
    test_v2(GEN9);

	test_v2(GEN10);

	test_v2(GEN11);

	return 0;
}

