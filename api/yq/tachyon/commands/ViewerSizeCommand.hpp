////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class ViewerSizeCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerSizeCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerSizeCommand(Viewer*, const Size2I&, const Param& p = {});
        virtual ~ViewerSizeCommand();
        
        static void init_info();

        const Size2I& size() const { return m_size; }
        int width() const { return m_size.x; }
        int height() const { return m_size.y; }
        
    private:
        const Size2I    m_size;
    };
}
