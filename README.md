Hal layers Sample 
===================
This sample try to figure out a way to solve the modularization problem. 


####Problem to solve
In this sample, we use two interfaces ```get_platform_id() ``` and ```submit_command()``` to show how to do modularization.```get_platform_id() ``` is a common interface to return platform id ; while ```submit_command()``` is a platform specific function, assume it is only available in gen9, but not implemented in gen11.  

####Key ideas

> - Class 
> - Template

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
```
template<class T>
int submit_command(HalBase *phal)
{
    T *pxhal = (T *)(phal);
    return pxhal->submit_command();
}
```

####Remaining Issues
>- The definition of HalGen9 and HalGen11 have to be included in HalBase.h . Can be controlled by pre-processors passed by build scripts
>- The instantiation code in common layer are not removed.  May use some compile-time technologies to create instances dynamically.