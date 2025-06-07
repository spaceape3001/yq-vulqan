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

    //! Instructs an object to roll (ie, around the local body X-axis) by the given amount
    class RollByCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(RollByCommand, OrientationCommand)
    public:
        RollByCommand(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RollByCommand(const RollByCommand&, const Header&);
        ~RollByCommand();
    
    private:
        Radian const  m_θ;
        
        RollByCommand(const RollByCommand&) = delete;
        RollByCommand(RollByCommand&&) = delete;
        RollByCommand& operator=(const RollByCommand&) = delete;
        RollByCommand& operator=(RollByCommand&&) = delete;
    };
}
