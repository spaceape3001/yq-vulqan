////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMinSize4D.hpp>

namespace yq::tachyon {
    class PMinSize⁴D : public Proxy, public IMinSize⁴D {
    public:
    
        using IMinSize⁴D::min_size;
    
        //!  Basic min_size in the 4I space
        Size4D      min_size() const { return m_min_size; }
        
        //!  Set min_size the min_size
        void        min_size(set_k, const Size4D&) override;
        void        min_size(set_k, x_k, double) override;
        void        min_size(set_k, y_k, double) override;
        void        min_size(set_k, z_k, double) override;
        void        min_size(set_k, w_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void        min_size(add_k, const Size4D&) override;
        void        min_size(add_k, x_k, double) override;
        void        min_size(add_k, y_k, double) override;
        void        min_size(add_k, z_k, double) override;
        void        min_size(add_k, w_k, double) override;

        void        min_size(multiply_k, double) override;
        void        min_size(multiply_k, const Vector4D&) override;
        void        min_size(multiply_k, x_k, double) override;
        void        min_size(multiply_k, y_k, double) override;
        void        min_size(multiply_k, z_k, double) override;
        void        min_size(multiply_k, w_k, double) override;
        
        bool        min_size(disabled_k) const override;
        bool        min_size(settable_k) const override;
        bool        min_size(addable_k) const override;
        bool        min_size(multipliable_k) const override;
        
        const Size4D&   min_size(ref_k) const { return m_min_size; }

        PMinSize⁴D(const IMinSize⁴D& i);
        virtual ~PMinSize⁴D();

    private:
        Size4D const m_min_size;
    };
}

