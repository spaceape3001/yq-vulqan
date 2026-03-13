////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ISize1D.hpp>

namespace yq::tachyon {
    class PSize¹D : public Proxy, public ISize¹D {
    public:
    
        using ISize¹D::size;
    
        //!  Basic size in the 1D space
        Size1D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size1D&) override;
        void        size(set_k, x_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Size1D&) override;
        void        size(add_k, x_k, double) override;

        void        size(multiply_k, double) override;
        void        size(multiply_k, const Vector1D&) override;
        void        size(multiply_k, x_k, double) override;
        
        bool        size(disabled_k) const override;
        bool        size(settable_k) const override;
        bool        size(addable_k) const override;
        bool        size(multipliable_k) const override;
        
        const Size1D&   size(ref_k) const { return m_size; }

        PSize¹D(const ISize¹D& i);
        virtual ~PSize¹D();

    private:
        Size1D        m_size;
    };
}

