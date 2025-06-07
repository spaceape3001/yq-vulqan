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
    class YawByCommand : public OrientationCommand {
        YQ_OBJECT_DECLARE(YawByCommand, OrientationCommand)
    public:
        YawByCommand(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        YawByCommand(const YawByCommand&, const Header&);
        
    private:
        Radian  m_θ;

        ~YawByCommand();
        YawByCommand(YawByCommand&&) = delete;
        YawByCommand(const YawByCommand&) = delete;
        YawByCommand& operator=(const YawByCommand&) = delete;
        YawByCommand& operator=(YawByCommand&&) = delete;
    };
}
