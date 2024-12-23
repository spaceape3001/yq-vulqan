////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowMoveCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowMoveCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowMoveCommand(Window*, const Vector2I&, const Param& p = {});
        virtual ~WindowMoveCommand();
        
        static void init_info();

        const Vector2I& position() const { return m_position; }
        int x() const { return m_position.x; }
        int y() const { return m_position.y; }
        
    private:
        const Vector2I    m_position;
    };
}
