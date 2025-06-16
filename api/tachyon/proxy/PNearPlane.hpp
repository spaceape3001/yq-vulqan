////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/INearPlane.hpp>

namespace yq::tachyon {
    class PNearPlane : public Proxy, public INearPlane {
    public:
    
        virtual double  near_plane() const override;

        virtual bool    near_plane(disabled_k) const override;
        virtual bool    near_plane(settable_k) const override;
        
        virtual void    near_plane(set_k, double) override;

        PNearPlane(const INearPlane& i);
        ~PNearPlane();

    private:
        const double  m_near_plane;
    };
}
