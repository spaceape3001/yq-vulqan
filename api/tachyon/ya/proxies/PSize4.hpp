////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/ISize4.hpp>

namespace yq::tachyon {
    class PSize⁴ : public Proxy, public ISize⁴ {
    public:
    
        //!  Basic size in the 4I space
        Size4D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size4D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        void        size(set_k, z_k, double) override;
        void        size(set_k, w_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Vector4D&) override;
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

        PSize⁴(const ISize⁴& i);
        virtual ~PSize⁴();

    private:
        Size4D        m_size;
    };
}

