////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <tachyon/interface/IMaxSize2.hpp>

namespace yq::tachyon {
    class PMaxSize² : public Proxy, public IMaxSize² {
    public:
    
        //!  Basic max_size in the 2I space
        Size2D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size2D&) override;
        void        max_size(set_k, x_k, double) override;
        void        max_size(set_k, y_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Vector2D&) override;
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

        PMaxSize²(const IMaxSize²& i);
        virtual ~PMaxSize²();

    private:
        Size2D        m_max_size;
    };
}

