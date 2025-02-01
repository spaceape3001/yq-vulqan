////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class ViewerAspectCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerAspectCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerAspectCommand(Viewer*, const Size2I&, const Param& p = {});
        virtual ~ViewerAspectCommand();
        
        static void init_info();

        const Size2I& aspect() const { return m_aspect; }
        int width() const { return m_aspect.x; }
        int height() const { return m_aspect.y; }
        
    private:
        const Size2I    m_aspect;
    };
}
