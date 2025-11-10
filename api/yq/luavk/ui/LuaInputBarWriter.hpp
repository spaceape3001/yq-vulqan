////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIInputBarWriter.hpp>

namespace yq::lua {
    class LuaInputBar;
    class LuaInputBarWriter : public tachyon::UIInputBarWriter {
    public:
        LuaInputBarWriter();
        LuaInputBarWriter(LuaInputBar*);
        LuaInputBarWriter(const LuaInputBarWriter&);
        ~LuaInputBarWriter();
        
        LuaInputBar* element();
    };
}
