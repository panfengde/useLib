//
// Created by panFeng on 2023/6/29.
//

#if defined(_WIN32)
    #define EXPORT_DLL extern "C" __declspec(dllexport)
#else
    #define EXPORT_DLL extern "C" __attribute__((visibility("default")))
#endif


#include <stdio.h>
#include<iostream>




EXPORT_DLL int hello() {
    std::cout << "this is new hello" << std::endl;
    return 100;
}