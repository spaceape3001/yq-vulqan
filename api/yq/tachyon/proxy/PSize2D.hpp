////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ISize2D.hpp>

namespace yq::tachyon {
    class PSize²D : public Proxy, public ISize²D {
    public:
    
        using ISize²D::size;
    
        //!  Basic size in the 2I space
        Size2D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size2D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Size2D&) override;
        void        size(add_k, x_k, double) override;
        void        size(add_k, y_k, double) override;

        void        size(multiply_k, double) override;
        void        size(multiply_k, const Vector2D&) override;
        void        size(multiply_k, x_k, double) override;
        void        size(multiply_k, y_k, double) override;
        
        bool        size(disabled_k) const override;
        bool        size(settable_k) const override;
        bool        size(addable_k) const override;
        bool        size(multipliable_k) const override;
        
        const Size2D&   size(ref_k) const { return m_size; }

        PSize²D(const ISize²D& i);
        virtual ~PSize²D();

    private:
        Size2D        m_size;
    };
}

