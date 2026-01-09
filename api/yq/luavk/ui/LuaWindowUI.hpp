////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/ui/layout/UIPanel.hpp>

namespace yq::tachyon {
    class LuaExecuteReply;

    class LuaWindowUI : public UIPanel {
        YQ_OBJECT_DECLARE(LuaWindowUI, UIPanel)
    public:
    
        LuaWindowUI(std::string_view, UIFlags flags={});
        LuaWindowUI(const LuaWindowUI&);
        virtual ~LuaWindowUI();
        
        LuaWindowUI* clone() const override;
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

