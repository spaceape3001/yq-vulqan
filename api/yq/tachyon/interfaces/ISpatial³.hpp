////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/interfaces/ISpatial.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/typedef/tensor44.hpp>

namespace yq { class Any; }

namespace yq::tachyon {
    class PSpatial³;
    
    class ISpatial³ : public ISpatial {
        YQ_INTERFACE_DECLARE(ISpatial³, PSpatial³)
    public:
        virtual uint8_t             spatial(dimensions_k) const override final { return 3; }
        
        virtual TachyonID           spatial(domain_k) const override;
        virtual Any                 spatial(l2d_k) const override;
        virtual Any                 spatial(d2l_k) const override;

        //! Who's our parent (should have a ISpatial³ too)
        virtual TachyonID           spatial³(domain_k) const { return {}; }
        
        //! Local to domain transform
        virtual Tensor44D           spatial³(l2d_k) const = 0;
        
        //! Domain to local transform
        virtual Tensor44D           spatial³(d2l_k) const = 0;

        static void init_info();
    };
}
