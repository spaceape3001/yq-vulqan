////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMaxSize1.hpp>

namespace yq::tachyon {
    class PMaxSize¹ : public Proxy, public IMaxSize¹ {
    public:
    
        //!  Basic max_size in the 1D space
        Size1D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size1D&) override;
        void        max_size(set_k, x_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Vector1D&) override;
        void        max_size(add_k, x_k, double) override;

        void        max_size(multiply_k, double) override;
        void        max_size(multiply_k, const Vector1D&) override;
        void        max_size(multiply_k, x_k, double) override;
        
        bool        max_size(disabled_k) const override;
        bool        max_size(settable_k) const override;
        bool        max_size(addable_k) const override;
        bool        max_size(multipliable_k) const override;
        
        const Size1D&   max_size(ref_k) const { return m_max_size; }

        PMaxSize¹(const IMaxSize¹& i);
        virtual ~PMaxSize¹();

    private:
        Size1D        m_max_size;
    };
}

