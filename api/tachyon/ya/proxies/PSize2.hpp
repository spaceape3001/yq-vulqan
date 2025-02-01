////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/ISize2.hpp>

namespace yq::tachyon {
    class PSize² : public Proxy, public ISize² {
    public:
    
        //!  Basic size in the 2I space
        Size2D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size2D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Vector2D&) override;
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

        PSize²(const ISize²& i);
        virtual ~PSize²();

    private:
        Size2D        m_size;
    };
}

