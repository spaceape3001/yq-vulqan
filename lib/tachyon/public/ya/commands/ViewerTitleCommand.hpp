////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerTitleCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerTitleCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerTitleCommand(Viewer*, std::string_view, const Param& p = {});
        virtual ~ViewerTitleCommand();
        
        static void init_info();
        
        const std::string&  title() const { return m_title; }
    private:
        std::string     m_title;
    };
}
