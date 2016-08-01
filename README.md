Hal layers Sample 
===================
This sample try to figure out a way to solve the modularization problem in hal layers and how to avoid platform code referred by common files. 


####Problem to solve
In this sample, we use two interfaces ```get_platform_id() ``` and ```submit_command()``` to show how to do modularization.
> -  ```get_platform_id() ``` is a platform specific function to return platform id 
> -  ```submit_command()```   is a platform specific function to submit commands. Each platform should have its own implementation.
> -  ```submit_x_engine()```  is a function only available from gen10+
> - ```load_kernel_binary()``` is a common function, not platform related.

####Key ideas

> - Class 
  Using multiple-layer hierarchy will bring casting effort in running time and let the code to invoke complex. To solve this problem, we put the limitation for class hierarchy, only two-layer allowed.

####Code Structure
>- HalBase.cpp & HalBase.h
Base class . common functions and non-platform code should be defined in common layers.
Platform class should derive from base class, i.e HalGen9 and HalGen11.
```get_platform_id() ``` returns the platform id 
```submit_command()``` will be overridden by the method defined in derived class. if this method not defined in derived class, base class one will be used which does nothing. 

>- HalGen9.cpp & HalGen11.cpp
Platform-specific class derived from HalBase. 
```submit_command()```  is not defined in ```HalGen11.cpp ``` to simulate the behavior of not-implemented functions on platform

>- haldemox.cpp
Code to simulate how to create instances of platform-classes and how to invoke interfaces at running time.


####How to avoid moving everything to C++
The cost will be very huge if we move everything to C++. It is better to keep C interfaces.
>-  Common functions: keep as C interfaces
>- Platform related functions: provide C interface to access.  
>
	```
	int HalCm_Submit_Command(pState)  
	{ 
		return pState->phal->submit_command();  
	}  
	```


####How to solve the platform files directly refered by common files
There are two violations in previous solution. 
>- The definition of HalGen9 and HalGen11 have to be included in HalBase.h 
>- The instantiation code in common layer are not removed.

We use custom build in Cmake to dynamically generate the header ```HalInit.h``` and instantiation code ```init()```. The python scripts locates in ```scripts\HeaderGenerator.py``` whose input is the list of supported platforms. 

Command to build code supports Gen9, Gen10 and Gen11 
```$cmake  -Wno-dev -G "Visual Studio %CMAKE_MODE_VS%%CMAKE_ARCH%" %BUILD_ROOT% -DGEN9=1 -DGEN10=1 -DGEN11=1```  
Command to build code supports Gen10 and Gen11 
```$cmake  -Wno-dev -G "Visual Studio %CMAKE_MODE_VS%%CMAKE_ARCH%" %BUILD_ROOT% -DGEN10=1 -DGEN11=1```