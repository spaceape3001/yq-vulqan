////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIInputBar.hpp>

namespace yq::lua {
    class LuaInputBarWriter;

    class LuaInputBar : public tachyon::UIInputBar {
        YQ_OBJECT_DECLARE(LuaInputBar, tachyon::UIInputBar)
    public:
        using Writer = LuaInputBarWriter;
    
        LuaInputBar(std::string_view, tachyon::UIFlags flags={});
        LuaInputBar(const LuaInputBar&);
        virtual ~LuaInputBar();
        
        static void init_meta();
        
    protected:
        LuaInputBar*    clone() const;

    private:
    };
}
