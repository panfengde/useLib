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
    testLoader.Load(std::string("/Users/panfeng/coder/myProject/LibUse/useLib/libLAB.dylib"));
    if (testLoader.libraryHandle_) {
#if defined(_WIN32)
        auto hello = (helloType) GetProcAddress(testLoader.libraryHandle_, "hello");
#else
        // 获取函数指针
        auto hello = reinterpret_cast<helloType>(dlsym(testLoader.libraryHandle_, "hello"));
#endif
        // 检查是否成功获取函数指针
        if (!hello) {
            std::cerr << "Cannot load symbol 'add': " << dlerror() << std::endl;
            return 1;
        }

        int result = hello();
        std::cout << result << std::endl;
        std::cout << "end" << std::endl;
    }
}
