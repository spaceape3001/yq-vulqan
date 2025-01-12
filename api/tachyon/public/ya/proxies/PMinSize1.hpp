////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/IMinSize1.hpp>

namespace yq::tachyon {
    class PMinSize¹ : public Proxy, public IMinSize¹ {
    public:
    
        //!  Basic min_size in the 1D space
        Size1D      min_size() const { return m_min_size; }
        
        //!  Set min_size the min_size
        void        min_size(set_k, const Size1D&) override;
        void        min_size(set_k, x_k, double) override;
        
        //!  Move the min_size (ie set to min_size + delta)
        void        min_size(add_k, const Vector1D&) override;
        void        min_size(add_k, x_k, double) override;

        void        min_size(multiply_k, double) override;
        void        min_size(multiply_k, const Vector1D&) override;
        void        min_size(multiply_k, x_k, double) override;
        
        bool        min_size(disabled_k) const override;
        bool        min_size(settable_k) const override;
        bool        min_size(addable_k) const override;
        bool        min_size(multipliable_k) const override;
        
        const Size1D&   min_size(ref_k) const { return m_min_size; }

        PMinSize¹(const IMinSize¹& i);
        virtual ~PMinSize¹();

    private:
        Size1D        m_min_size;
    };
}

