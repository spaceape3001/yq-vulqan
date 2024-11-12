////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraCommandInfo : public post::CommandInfo {
    public:
        CameraCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraCommand : public post::Command, public CameraBind {
        YQ_OBJECT_INFO(CameraCommandInfo)
        YQ_OBJECT_DECLARE(CameraCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        CameraCommand(Camera*, const Param& p = {});
        virtual ~CameraCommand();
        
        static void init_info();
    };
}
