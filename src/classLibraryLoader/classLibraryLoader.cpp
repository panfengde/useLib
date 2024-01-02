//
// Created by panFeng on 2023/6/29.
//

#include "classLibraryLoader.h"


#include <codecvt>
#include <locale>

namespace mao::library {
    classLibraryLoader::classLibraryLoader() { libraryHandle_ = nullptr; }
    classLibraryLoader::~classLibraryLoader() { Free(); }

    bool classLibraryLoader::Load(std::string str_utf8_dllfilepath) {
#if defined(_WIN32)
        std::cout << "string path" << std::endl;
        std::wstring_convert<std::codecvt_utf8<wchar_t> > conv;
        std::wstring strpath = conv.from_bytes(str_utf8_dllfilepath);
        libraryHandle_ =
                LoadLibraryExW(strpath.c_str(), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
        if (libraryHandle_ == nullptr) {
            return false;
        }
        return true;
#else
        // 动态加载共享库
        libraryHandle_ = dlopen(str_utf8_dllfilepath.c_str(), RTLD_LAZY);
        if (!libraryHandle_) {
            std::cerr << "Cannot load library: " << dlerror() << std::endl;
            return 1;
        }
        return true;
#endif
    }

    void classLibraryLoader::Free() {
#if defined(_WIN32)
        if (libraryHandle_ != nullptr) {
            ::FreeLibrary((HMODULE)libraryHandle_);
            libraryHandle_ = nullptr;
        }
#else
        // 关闭共享库
        dlclose(libraryHandle_);
#endif
    }
} // namespace mao::library
