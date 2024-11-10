////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class ViewerMoveCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerMoveCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerMoveCommand(Viewer*, const Vector2I&, const Param& p = {});
        virtual ~ViewerMoveCommand();
        
        static void init_info();

        const Vector2I& position() const { return m_position; }
        int x() const { return m_position.x; }
        int y() const { return m_position.y; }
        
    private:
        const Vector2I    m_position;
    };
}
