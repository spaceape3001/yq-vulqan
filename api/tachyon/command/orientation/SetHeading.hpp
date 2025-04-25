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

    //! Instructs an object to yaw (ie, around the local body Z-axis) by the given amount
    class SetHeading : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetHeading, OrientationCommand)
    public:
        SetHeading(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetHeading(const SetHeading&, const Header&);
        SetHeading(const Header&);
        
    private:
        Radian  m_θ = ZERO;

        ~SetHeading();
        SetHeading(SetHeading&&) = delete;
        SetHeading(const SetHeading&) = delete;
        SetHeading& operator=(const SetHeading&) = delete;
        SetHeading& operator=(SetHeading&&) = delete;
    };
}
