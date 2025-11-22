////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UIConcreteMetaList.hpp>
#include <yq/core/Object.hpp>

namespace yq::tachyon {

    template <SomeObject T>
    class UIBuildableMetaList : public UIConcreteMetaList {
    public:
        UIBuildableMetaList(UIFlags flags={}) : UIConcreteMetaList(&meta<T>(), flags) {}
        UIBuildableMetaList(std::string_view szTitle, UIFlags flags={}) : UIConcreteMetaList(szTitle, &meta<T>(), flags) {}
    };
}
