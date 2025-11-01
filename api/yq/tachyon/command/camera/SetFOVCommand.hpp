////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CameraCommand.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class SetFOVCommand : public CameraCommand {
        YQ_OBJECT_DECLARE(SetFOVCommand, CameraCommand)
    public:
    
        SetFOVCommand(const Header&, unit::Degree);
        
        static void init_meta();
        
        unit::Degree        fov() const { return m_fov; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetFOVCommand(const SetFOVCommand&, const Header&);
        virtual ~SetFOVCommand();
    
    private:
        unit::Degree m_fov;
        
        SetFOVCommand(const SetFOVCommand&) = delete;
        SetFOVCommand(SetFOVCommand&&) = delete;
        SetFOVCommand& operator=(const SetFOVCommand&) = delete;
        SetFOVCommand& operator=(SetFOVCommand&&) = delete;
    };
}
