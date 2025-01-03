////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowAspectCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowAspectCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowAspectCommand(WindowID, const Size2I&, const Param& p = {});
        WindowAspectCommand(Window*, const Size2I&, const Param& p = {});
        virtual ~WindowAspectCommand();
        
        static void init_info();

        const Size2I& aspect() const { return m_aspect; }
        int width() const { return m_aspect.x; }
        int height() const { return m_aspect.y; }
        
    private:
        const Size2I    m_aspect;
    };
}
