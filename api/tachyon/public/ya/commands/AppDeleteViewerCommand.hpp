////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/AppCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class AppDeleteViewerCommand : public AppCommand {
        YQ_OBJECT_DECLARE(AppDeleteViewerCommand, AppCommand)
    public:
    
        AppDeleteViewerCommand(Viewer*);
        virtual ~AppDeleteViewerCommand();
        
        static void init_info();
    
        Viewer* viewer() const { return m_viewer; }
    
    private:
        Viewer* const m_viewer;
    };
}
