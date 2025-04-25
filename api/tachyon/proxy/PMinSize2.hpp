////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/IMinSize2.hpp>

namespace yq::tachyon {
    class PMinSize² : public Proxy, public IMinSize² {
    public:
    
        //!  Basic min_size in the 2I space
        Size2D      min_size() const { return m_min_size; }
        
        //!  Set min_size the min_size
        void        min_size(set_k, const Size2D&) override;
        void        min_size(set_k, x_k, double) override;
        void        min_size(set_k, y_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void        min_size(add_k, const Vector2D&) override;
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

        PMinSize²(const IMinSize²& i);
        virtual ~PMinSize²();

    private:
        Size2D        m_min_size;
    };
}

