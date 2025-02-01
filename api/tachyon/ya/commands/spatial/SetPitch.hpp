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

    //! Instructs an object to pitch (ie, around the local body Y-axis) by the given amount
    class SetPitch : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPitch, SpatialCommand)
    public:
        SetPitch(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPitch(const Header&);
        SetPitch(const SetPitch&, const Header&);
        ~SetPitch();
        
    private:
        Radian m_θ;
        
        SetPitch(const SetPitch&);
        SetPitch(SetPitch&&);
        SetPitch& operator=(const SetPitch&);
        SetPitch& operator=(SetPitch&&);
    };
}
