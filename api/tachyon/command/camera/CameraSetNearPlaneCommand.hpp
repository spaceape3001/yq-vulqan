////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class CameraSetNearPlaneCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(CameraSetNearPlaneCommand, CameraCommand)
    public:
    
        CameraSetNearPlaneCommand(const Header&, double);
        
        static void init_info();
        
        double  near() const { return m_near; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        CameraSetNearPlaneCommand(const CameraSetNearPlaneCommand&, const Header&);
        virtual ~CameraSetNearPlaneCommand();
    
    private:
        double m_near;
        
        CameraSetNearPlaneCommand(const CameraSetNearPlaneCommand&) = delete;
        CameraSetNearPlaneCommand(CameraSetNearPlaneCommand&&) = delete;
        CameraSetNearPlaneCommand& operator=(const CameraSetNearPlaneCommand&) = delete;
        CameraSetNearPlaneCommand& operator=(CameraSetNearPlaneCommand&&) = delete;
    };
}
