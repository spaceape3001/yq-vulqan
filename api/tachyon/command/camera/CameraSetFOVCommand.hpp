////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class CameraSetFOVCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraSetFOVCommand, CameraCommand)
    public:
    
        CameraSetFOVCommand(const Header&, unit::Degree);
        
        static void init_info();
        
        unit::Degree        fov() const { return m_fov; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        CameraSetFOVCommand(const CameraSetFOVCommand&, const Header&);
        virtual ~CameraSetFOVCommand();
    
    private:
        unit::Degree m_fov;
        
        CameraSetFOVCommand(const CameraSetFOVCommand&) = delete;
        CameraSetFOVCommand(CameraSetFOVCommand&&) = delete;
        CameraSetFOVCommand& operator=(const CameraSetFOVCommand&) = delete;
        CameraSetFOVCommand& operator=(CameraSetFOVCommand&&) = delete;
    };
}
