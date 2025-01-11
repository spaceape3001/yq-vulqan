////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to set roll (ie, around the local body X-axis) to given value
    class SetRoll : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetRoll, SpatialCommand)
    public:
        SetRoll(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetRoll(const Header&);
        SetRoll(const SetRoll&, const Header&);
        ~SetRoll();
    
    private:
        Radian m_θ = ZERO;
        
        SetRoll(const SetRoll&) = delete;
        SetRoll(SetRoll&&) = delete;
        SetRoll& operator=(const SetRoll&) = delete;
        SetRoll& operator=(SetRoll&&) = delete;
    };
}
