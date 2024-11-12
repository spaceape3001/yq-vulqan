////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/viewer/ControllerBind.hpp>

namespace yq::tachyon {
    class Controller;

    class ControllerCommandInfo : public post::CommandInfo {
    public:
        ControllerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ControllerCommand : public post::Command, public ControllerBind {
        YQ_OBJECT_INFO(ControllerCommandInfo)
        YQ_OBJECT_DECLARE(ControllerCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        ControllerCommand(Controller*, const Param& p = {});
        virtual ~ControllerCommand();
        
        static void init_info();
    };
}
