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

    //! Instructs an object to yaw (ie, around the local body Z-axis) by the given amount
    class YawBy : public SpatialCommand {
        YQ_OBJECT_DECLARE(YawBy, SpatialCommand)
    public:
        YawBy(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        YawBy(const YawBy&, const Header&);
        
    private:
        Radian const  m_θ;

        ~YawBy();
        YawBy(YawBy&&) = delete;
        YawBy(const YawBy&) = delete;
        YawBy& operator=(const YawBy&) = delete;
        YawBy& operator=(YawBy&&) = delete;
    };
}
