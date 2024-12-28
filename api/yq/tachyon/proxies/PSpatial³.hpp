////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/ISpatial³.hpp>
#include <yq/tensor/Tensor44.hpp>

namespace yq::tachyon {

    class PSpatial³ : public Proxy, public ISpatial³ {
    public:
        
        PSpatial³(const ISpatial³&);
        ~PSpatial³();

        virtual TachyonID           spatial(domain_k) const override;
        virtual Any                 spatial(l2d_k) const override;
        virtual Any                 spatial(d2l_k) const override;

        //! Who's our parent (should have a ISpatial³ too)
        virtual TachyonID           spatial³(domain_k) const override;
        
        //! Local to domain transform
        virtual Tensor44D           spatial³(l2d_k) const override;;
        
        //! Domain to local transform
        virtual Tensor44D           spatial³(d2l_k) const override;;
        
        const Tensor44D&            spatial³(ref_k, d2l_k) const { return m_D2L; }
        const Tensor44D&            spatial³(ref_k, l2d_k) const { return m_L2D; }

    private:
        TachyonID   m_domain;
        Tensor44D   m_L2D, m_D2L;

    };

}
