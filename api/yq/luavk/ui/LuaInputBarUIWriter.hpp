////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/ui/LuaInputBarUI.hpp>
#include <yq/tachyon/ui/input/UIInputBarWriter.hpp>

namespace yq::tachyon {
    class LuaInputBarUI;
    class LuaInputBarUIWriter : public UIElementWriter {
    public:
        LuaInputBarUIWriter();
        LuaInputBarUIWriter(LuaInputBarUI*);
        LuaInputBarUIWriter(const LuaInputBarUIWriter&);
        ~LuaInputBarUIWriter();
        
        LuaInputBarUI* element();

        LuaInputBarUIWriter   capacity(size_t);
        LuaInputBarUIWriter   label(std::string_view);
    };
}
