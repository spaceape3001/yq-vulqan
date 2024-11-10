////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowTitleCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowTitleCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowTitleCommand(Viewer*, std::string_view, const Param& p = {});
        virtual ~WindowTitleCommand();
        
        static void init_info();
        
        const std::string&  title() const { return m_title; }
    private:
        std::string     m_title;
    };
}
