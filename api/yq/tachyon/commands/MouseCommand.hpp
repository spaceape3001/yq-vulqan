////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/viewer/ViewerBind.hpp>

namespace yq::tachyon {
    class MouseCommandInfo : public post::CommandInfo {
    public:
        MouseCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class MouseCommand : public post::Command, public ViewerBind {
        YQ_OBJECT_INFO(MouseCommandInfo)
        YQ_OBJECT_DECLARE(MouseCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        MouseCommand(Viewer*, const Param& p = {});
        virtual ~MouseCommand();
        
        static void init_info();
    };
}
