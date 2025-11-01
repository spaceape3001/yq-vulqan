////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IOrientation2.hpp>

namespace yq::tachyon {

    class POrientation² : public Proxy, public IOrientation² {
    public:
    
        Spinor2D        orientation() const override;
        bool            orientation(disabled_k) const override;
        bool            orientation(settable_k) const override;
        bool            orientation(rotatable_k) const override;
        
        void            orientation(set_k, const Spinor2D&) override;
        
        void            orientation(set_k, heading_k, Radian) override;

        void            orientation(rotate_k, const Spinor2D&) override;
        void            orientation(rotate_k, Radian) override;
        
        void            orientation(rotate_k, yaw_k, Radian) override;
        
        Radian          heading() const;

        const Spinor2D&    orientation(ref_k) const { return m_orientation; }

        POrientation²(const IOrientation²& i);
        ~POrientation²();
    private:
        const Spinor2D        m_orientation;
    };
}
