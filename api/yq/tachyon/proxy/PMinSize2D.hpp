////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMinSize2D.hpp>

namespace yq::tachyon {
    class PMinSize²D : public Proxy, public IMinSize²D {
    public:
    
        using IMinSize²D::min_size;
    
        //!  Basic min_size in the 2I space
        Size2D      min_size() const { return m_min_size; }
        
        //!  Set min_size the min_size
        void        min_size(set_k, const Size2D&) override;
        void        min_size(set_k, x_k, double) override;
        void        min_size(set_k, y_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void        min_size(add_k, const Size2D&) override;
        void        min_size(add_k, x_k, double) override;
        void        min_size(add_k, y_k, double) override;

        void        min_size(multiply_k, double) override;
        void        min_size(multiply_k, const Vector2D&) override;
        void        min_size(multiply_k, x_k, double) override;
        void        min_size(multiply_k, y_k, double) override;
        
        bool        min_size(disabled_k) const override;
        bool        min_size(settable_k) const override;
        bool        min_size(addable_k) const override;
        bool        min_size(multipliable_k) const override;
        
        const Size2D&   min_size(ref_k) const { return m_min_size; }

        PMinSize²D(const IMinSize²D& i);
        virtual ~PMinSize²D();

    private:
        Size2D const  m_min_size;
    };
}

