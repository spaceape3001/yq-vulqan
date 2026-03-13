////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ISize4D.hpp>

namespace yq::tachyon {
    class PSize⁴D : public Proxy, public ISize⁴D {
    public:
    
        using ISize⁴D::size;
    
        //!  Basic size in the 4I space
        Size4D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size4D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        void        size(set_k, z_k, double) override;
        void        size(set_k, w_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Size4D&) override;
        void        size(add_k, x_k, double) override;
        void        size(add_k, y_k, double) override;
        void        size(add_k, z_k, double) override;
        void        size(add_k, w_k, double) override;

        void        size(multiply_k, double) override;
        void        size(multiply_k, const Vector4D&) override;
        void        size(multiply_k, x_k, double) override;
        void        size(multiply_k, y_k, double) override;
        void        size(multiply_k, z_k, double) override;
        void        size(multiply_k, w_k, double) override;
        
        bool        size(disabled_k) const override;
        bool        size(settable_k) const override;
        bool        size(addable_k) const override;
        bool        size(multipliable_k) const override;
        
        const Size4D&   size(ref_k) const { return m_size; }

        PSize⁴D(const ISize⁴D& i);
        virtual ~PSize⁴D();

    private:
        Size4D        m_size;
    };
}

