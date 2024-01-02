//
// Created by panFeng on 2023/6/29.
//

#ifndef USELIB_CLASSLIBRARYLOADER_H
#define USELIB_CLASSLIBRARYLOADER_H

#include <string>
#include <type_traits>
#include <utility>
#include<iostream>
#if defined(_WIN32)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

namespace mao::library {
    class classLibraryLoader {
    public:
        classLibraryLoader();

        ~classLibraryLoader();

        bool Load(std::string str_utf8_dllfilepath);

        void Free();

        void* libraryHandle_;
    };
}  // namespace mao::library

#endif //USELIB_CLASSLIBRARYLOADER_H
