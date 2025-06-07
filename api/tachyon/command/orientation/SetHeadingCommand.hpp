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
    class SetHeadingCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetHeadingCommand, OrientationCommand)
    public:
        SetHeadingCommand(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetHeadingCommand(const SetHeadingCommand&, const Header&);
        SetHeadingCommand(const Header&);
        
    private:
        Radian  m_θ = ZERO;

        ~SetHeadingCommand();
        SetHeadingCommand(SetHeadingCommand&&) = delete;
        SetHeadingCommand(const SetHeadingCommand&) = delete;
        SetHeadingCommand& operator=(const SetHeadingCommand&) = delete;
        SetHeadingCommand& operator=(SetHeadingCommand&&) = delete;
    };
}
