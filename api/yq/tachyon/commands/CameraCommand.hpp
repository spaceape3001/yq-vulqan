////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraCommandInfo : public CommandInfo {
    public:
        CameraCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraCommand : public Command, public CameraBind {
        YQ_OBJECT_INFO(CameraCommandInfo)
        YQ_OBJECT_DECLARE(CameraCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        CameraCommand(const Camera*, const Param& p = {});
        CameraCommand(CameraID, const Param& p = {});
        virtual ~CameraCommand();
        
        static void init_info();
    };
}
