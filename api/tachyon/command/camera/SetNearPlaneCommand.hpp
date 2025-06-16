////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class SetNearPlaneCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(SetNearPlaneCommand, CameraCommand)
    public:
    
        SetNearPlaneCommand(const Header&, double);
        
        static void init_info();
        
        double  near() const { return m_near; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetNearPlaneCommand(const SetNearPlaneCommand&, const Header&);
        virtual ~SetNearPlaneCommand();
    
    private:
        double m_near;
        
        SetNearPlaneCommand(const SetNearPlaneCommand&) = delete;
        SetNearPlaneCommand(SetNearPlaneCommand&&) = delete;
        SetNearPlaneCommand& operator=(const SetNearPlaneCommand&) = delete;
        SetNearPlaneCommand& operator=(SetNearPlaneCommand&&) = delete;
    };
}
