////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/AppCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class AppDeleteViewerCommand : public AppCommand {
        YQ_OBJECT_DECLARE(AppDeleteViewerCommand, AppCommand)
    public:
    
        struct Param : public AppCommand::Param {
        };
    
        AppDeleteViewerCommand(Viewer*, const Param& p = {});
        virtual ~AppDeleteViewerCommand();
        
        static void init_info();
    
        Viewer* viewer() const { return m_viewer; }
    
    private:
        Viewer* const m_viewer;
    };
}
