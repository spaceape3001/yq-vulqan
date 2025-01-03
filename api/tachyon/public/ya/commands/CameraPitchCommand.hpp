////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class CameraPitchCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraPitchCommand, CameraCommand)
    public:
    
        struct Param : public CameraCommand::Param {
        };
    
        CameraPitchCommand(Camera*, unit::Radian amt, const Param& p = {});
        virtual ~CameraPitchCommand();
        
        static void init_info();
        
        unit::Radian    angle() const { return m_angle; }
    private:
        const unit::Radian  m_angle;
    };
}
