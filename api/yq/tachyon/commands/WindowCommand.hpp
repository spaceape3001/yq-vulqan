////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class WindowCommandInfo : public post::CommandInfo {
    public:
        WindowCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowCommand : public post::Command, public ViewerBind {
        YQ_OBJECT_INFO(WindowCommandInfo)
        YQ_OBJECT_DECLARE(WindowCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        WindowCommand(Viewer*, const Param& p = {});
        virtual ~WindowCommand();
        
        static void init_info();
    };
}
