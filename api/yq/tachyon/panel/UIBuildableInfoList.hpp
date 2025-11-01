////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/panel/UIConcreteInfoList.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    template <SomeTachyon T>
    class UIBuildableInfoList : public UIConcreteInfoList {
    public:
        UIBuildableInfoList(UIFlags flags={}) : UIConcreteInfoList(&meta<T>(), flags) {}
        UIBuildableInfoList(std::string_view szTitle, UIFlags flags={}) : UIConcreteInfoList(szTitle, &meta<T>(), flags) {}
    };
}
