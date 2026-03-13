////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size2.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMaxSize2D.hpp>

namespace yq::tachyon {
    class PMaxSize²D : public Proxy, public IMaxSize²D {
    public:
    
        using IMaxSize²D::max_size;
    
        //!  Basic max_size in the 2I space
        Size2D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size2D&) override;
        void        max_size(set_k, x_k, double) override;
        void        max_size(set_k, y_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Size2D&) override;
        void        max_size(add_k, x_k, double) override;
        void        max_size(add_k, y_k, double) override;

        void        max_size(multiply_k, double) override;
        void        max_size(multiply_k, const Vector2D&) override;
        void        max_size(multiply_k, x_k, double) override;
        void        max_size(multiply_k, y_k, double) override;
        
        bool        max_size(disabled_k) const override;
        bool        max_size(settable_k) const override;
        bool        max_size(addable_k) const override;
        bool        max_size(multipliable_k) const override;
        
        const Size2D&   max_size(ref_k) const { return m_max_size; }

        PMaxSize²D(const IMaxSize²D& i);
        virtual ~PMaxSize²D();

    private:
        Size2D const m_max_size;
    };
}

