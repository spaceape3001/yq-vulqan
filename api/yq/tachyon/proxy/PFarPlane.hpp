////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IFarPlane.hpp>

namespace yq::tachyon {
    class PFarPlane : public Proxy, public IFarPlane {
    public:
    
        virtual double  far_plane() const override;

        virtual bool    far_plane(disabled_k) const override;
        virtual bool    far_plane(settable_k) const override;
        
        virtual void    far_plane(set_k, double) override;

        PFarPlane(const IFarPlane& i);
        ~PFarPlane();

    private:
        const double  m_far_plane;
    };
}
