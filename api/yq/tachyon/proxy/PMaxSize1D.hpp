////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size1.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMaxSize1D.hpp>

namespace yq::tachyon {
    class PMaxSize¹D : public Proxy, public IMaxSize¹D {
    public:
    
        using IMaxSize¹D::max_size;
    
        //!  Basic max_size in the 1D space
        Size1D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size1D&) override;
        void        max_size(set_k, x_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Size1D&) override;
        void        max_size(add_k, x_k, double) override;

        void        max_size(multiply_k, double) override;
        void        max_size(multiply_k, const Vector1D&) override;
        void        max_size(multiply_k, x_k, double) override;
        
        bool        max_size(disabled_k) const override;
        bool        max_size(settable_k) const override;
        bool        max_size(addable_k) const override;
        bool        max_size(multipliable_k) const override;
        
        const Size1D&   max_size(ref_k) const { return m_max_size; }

        PMaxSize¹D(const IMaxSize¹D& i);
        virtual ~PMaxSize¹D();

    private:
        Size1D const m_max_size;
    };
}

