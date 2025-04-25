////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <tachyon/interface/IMaxSize4.hpp>

namespace yq::tachyon {
    class PMaxSize⁴ : public Proxy, public IMaxSize⁴ {
    public:
    
        //!  Basic max_size in the 4I space
        Size4D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size4D&) override;
        void        max_size(set_k, x_k, double) override;
        void        max_size(set_k, y_k, double) override;
        void        max_size(set_k, z_k, double) override;
        void        max_size(set_k, w_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Vector4D&) override;
        void        max_size(add_k, x_k, double) override;
        void        max_size(add_k, y_k, double) override;
        void        max_size(add_k, z_k, double) override;
        void        max_size(add_k, w_k, double) override;

        void        max_size(multiply_k, double) override;
        void        max_size(multiply_k, const Vector4D&) override;
        void        max_size(multiply_k, x_k, double) override;
        void        max_size(multiply_k, y_k, double) override;
        void        max_size(multiply_k, z_k, double) override;
        void        max_size(multiply_k, w_k, double) override;
        
        bool        max_size(disabled_k) const override;
        bool        max_size(settable_k) const override;
        bool        max_size(addable_k) const override;
        bool        max_size(multipliable_k) const override;
        
        const Size4D&   max_size(ref_k) const { return m_max_size; }

        PMaxSize⁴(const IMaxSize⁴& i);
        virtual ~PMaxSize⁴();

    private:
        Size4D        m_max_size;
    };
}

