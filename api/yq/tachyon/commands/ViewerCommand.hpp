////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerCommandInfo : public post::CommandInfo {
    public:
        ViewerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerCommand : public post::Command, public ViewerBind {
        YQ_OBJECT_INFO(ViewerCommandInfo)
        YQ_OBJECT_DECLARE(ViewerCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        ViewerCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCommand();
        
        static void init_info();
    };
}
