//
// Created by panFeng on 2023/6/29.
//

#ifndef USELIB_CLASSLIBRARYLOADER_H
#define USELIB_CLASSLIBRARYLOADER_H

#include <string>
#include <type_traits>
#include <utility>
#include <windows.h>
#include<iostream>

namespace mao::library {
    class classLibraryLoader {
    public:
        classLibraryLoader();

        ~classLibraryLoader();

        bool Load(std::string str_utf8_dllfilepath);

        void Free();

        HMODULE libraryHandle_;
    };
}  // namespace mao::library

#endif //USELIB_CLASSLIBRARYLOADER_H
