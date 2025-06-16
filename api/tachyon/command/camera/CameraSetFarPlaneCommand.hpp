////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class CameraSetFarPlaneCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraSetFarPlaneCommand, CameraCommand)
    public:
    
        CameraSetFarPlaneCommand(const Header&, double);
        
        static void init_info();
        
        double  near() const { return m_near; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        CameraSetFarPlaneCommand(const CameraSetFarPlaneCommand&, const Header&);
        virtual ~CameraSetFarPlaneCommand();
    
    private:
        double m_near;
        
        CameraSetFarPlaneCommand(const CameraSetFarPlaneCommand&) = delete;
        CameraSetFarPlaneCommand(CameraSetFarPlaneCommand&&) = delete;
        CameraSetFarPlaneCommand& operator=(const CameraSetFarPlaneCommand&) = delete;
        CameraSetFarPlaneCommand& operator=(CameraSetFarPlaneCommand&&) = delete;
    };
}
