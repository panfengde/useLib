//
// Created by panFeng on 2023/6/29.
//


#include "classLibraryLoader/classLibraryLoader.h"
#include "classLibraryLoader/classLibraryLoader.cpp"
#include<iostream>

typedef int (*helloType)();

int main() {
    mao::library::classLibraryLoader testLoader;
    // testLoader.Load(std::string("E:\\code\\c\\Dynamically_calling_dynamic_libraries\\helloLib\\lib\\libLAB.dll"));
    testLoader.Load(std::string("..\\libLAB.dll"));
    if (testLoader.libraryHandle_) {
        std::cout << "goggo" << std::endl;
        auto hello = (helloType) GetProcAddress(testLoader.libraryHandle_, "hello");
        if (hello!= nullptr){
            std::cout << "xxxxx" << std::endl;
            int result=hello();
            std::cout << result << std::endl;
        }
        std::cout << "end" << std::endl;

    }
}
