////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to pitch (ie, around the local body Y-axis) by the given amount
    class SetPitchCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetPitchCommand, OrientationCommand)
    public:
        SetPitchCommand(const Header&, Radian θ);
    
        static void init_meta();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPitchCommand(const Header&);
        SetPitchCommand(const SetPitchCommand&, const Header&);
        ~SetPitchCommand();
        
    private:
        Radian m_θ;
        
        SetPitchCommand(const SetPitchCommand&);
        SetPitchCommand(SetPitchCommand&&);
        SetPitchCommand& operator=(const SetPitchCommand&);
        SetPitchCommand& operator=(SetPitchCommand&&);
    };
}
