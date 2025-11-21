////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIInputBarWriter.hpp>

namespace yq::tachyon {
    class LuaInputBar;
    class LuaInputBarWriter : public UIElementWriter {
    public:
        LuaInputBarWriter();
        LuaInputBarWriter(LuaInputBar*);
        LuaInputBarWriter(const LuaInputBarWriter&);
        ~LuaInputBarWriter();
        
        LuaInputBar* element();

        LuaInputBarWriter   capacity(size_t);
        LuaInputBarWriter   label(std::string_view);
    };
}
