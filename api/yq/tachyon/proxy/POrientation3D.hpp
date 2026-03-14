////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IOrientation3D.hpp>

namespace yq::tachyon {

    class POrientation³D : public Proxy, public IOrientation³D {
    public:
    
        Quaternion3D    orientation() const override;
        bool            orientation(disabled_k) const override;
        bool            orientation(settable_k) const override;
        bool            orientation(rotatable_k) const override;
        
        void            orientation(set_k, const Quaternion3D&) override;
        void            orientation(set_k, hpr_k, Radian, Radian, Radian) override;
        
        void            orientation(set_k, heading_k, Radian) override;
        void            orientation(set_k, pitch_k, Radian) override;
        void            orientation(set_k, roll_k, Radian) override;

        void            orientation(rotate_k, const Quaternion3D&) override;
        void            orientation(rotate_k, const unit::Radian3D&) override;
        
        void            orientation(rotate_k, pitch_k, Radian) override;
        void            orientation(rotate_k, roll_k, Radian) override;
        void            orientation(rotate_k, yaw_k, Radian) override;
        
        Radian          heading() const;
        Radian          pitch() const;
        Radian          roll() const;

        const Quaternion3D&    orientation(ref_k) const { return m_orientation; }

        POrientation³D(const IOrientation³D& i);
        ~POrientation³D();
    private:
        const Quaternion3D        m_orientation;
    };
}
