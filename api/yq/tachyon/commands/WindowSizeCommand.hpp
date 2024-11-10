////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowSizeCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowSizeCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowSizeCommand(Viewer*, const Size2I&, const Param& p = {});
        virtual ~WindowSizeCommand();
        
        static void init_info();

        const Size2I& size() const { return m_size; }
        int width() const { return m_size.x; }
        int height() const { return m_size.y; }
        
    private:
        const Size2I    m_size;
    };
}
