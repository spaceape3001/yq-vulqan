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

    //! Instructs an object to set roll (ie, around the local body X-axis) to given value
    class SetRollCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetRollCommand, OrientationCommand)
    public:
        SetRollCommand(const Header&, Radian θ);
    
        static void init_meta();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRollCommand(const Header&);
        SetRollCommand(const SetRollCommand&, const Header&);
        ~SetRollCommand();
    
    private:
        Radian m_θ = ZERO;
        
        SetRollCommand(const SetRollCommand&) = delete;
        SetRollCommand(SetRollCommand&&) = delete;
        SetRollCommand& operator=(const SetRollCommand&) = delete;
        SetRollCommand& operator=(SetRollCommand&&) = delete;
    };
}
