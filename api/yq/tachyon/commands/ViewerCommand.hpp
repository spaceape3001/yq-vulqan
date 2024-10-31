////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerCommandInfo : public post::CommandInfo {
    public:
        ViewerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerCommand : public post::Command {
        YQ_OBJECT_INFO(ViewerCommandInfo)
        YQ_OBJECT_DECLARE(ViewerCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        ViewerCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCommand();
        
        Viewer*     viewer() const { return m_viewer; }
        
    private:
        Viewer*     m_viewer    = nullptr;
    };
}
