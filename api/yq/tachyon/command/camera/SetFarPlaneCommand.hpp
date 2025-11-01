////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class SetFarPlaneCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(SetFarPlaneCommand, CameraCommand)
    public:
    
        SetFarPlaneCommand(const Header&, double);
        
        static void init_meta();
        
        double  far() const { return m_far; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetFarPlaneCommand(const SetFarPlaneCommand&, const Header&);
        virtual ~SetFarPlaneCommand();
    
    private:
        double m_far;
        
        SetFarPlaneCommand(const SetFarPlaneCommand&) = delete;
        SetFarPlaneCommand(SetFarPlaneCommand&&) = delete;
        SetFarPlaneCommand& operator=(const SetFarPlaneCommand&) = delete;
        SetFarPlaneCommand& operator=(SetFarPlaneCommand&&) = delete;
    };
}
