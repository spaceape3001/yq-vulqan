////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>

namespace yq::lua {
    class LuaExecuteReply;

    class LuaWindow : public tachyon::UIWindow {
        YQ_OBJECT_DECLARE(LuaWindow, tachyon::UIWindow)
    public:
    
        LuaWindow(std::string_view, tachyon::UIFlags flags={});
        LuaWindow(const LuaWindow&);
        virtual ~LuaWindow();
        
        LuaWindow* clone() const override;
        static void init_meta();
        void content() override;
        
        void    submit(const LuaExecuteReply&);
        void    tvm(set_k, tachyon::TypedID);
        
        void    debug(std::string_view);
        void    info(std::string_view);
        
        class Input;
        class Console;

    private:
    
        Input*              m_input     = nullptr;
        Console*            m_console   = nullptr;
    };
}

