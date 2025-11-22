////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindowWriter.hpp>
#include <yq/typedef/color.hpp>

namespace yq::tachyon {
    class LuaWindowUI;

    class LuaWindowUIWriter : public UIWindowWriter {
    public:
    public:
        LuaWindowUIWriter();
        LuaWindowUIWriter(LuaWindowUI*);
        LuaWindowUIWriter(const LuaWindowUIWriter&);
        ~LuaWindowUIWriter();
        
        LuaWindowUI*  element();
    };
}
