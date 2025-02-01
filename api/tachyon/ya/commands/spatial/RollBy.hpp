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

    //! Instructs an object to roll (ie, around the local body X-axis) by the given amount
    class RollBy : public SpatialCommand {
        YQ_OBJECT_DECLARE(RollBy, SpatialCommand)
    public:
        RollBy(const Header&, Radian θ);
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        RollBy(const RollBy&, const Header&);
        ~RollBy();
    
    private:
        Radian const  m_θ;
        
        RollBy(const RollBy&) = delete;
        RollBy(RollBy&&) = delete;
        RollBy& operator=(const RollBy&) = delete;
        RollBy& operator=(RollBy&&) = delete;
    };
}
