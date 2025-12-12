////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ICount1.hpp>

namespace yq::tachyon {
    class PCount¹ : public Proxy, public ICount¹  /* TODO: public ICount¹I, public ICount¹, public ICount */  {
    public:
    
        Vector1U    count() const override {  return m_count;  }
        bool        count(disabled_k) const override;
        bool        count(settable_k) const override;
        bool        count(addable_k) const override;
        bool        count(multipliable_k) const override;
        
        void        count(set_k, const Vector1U&) override;
        void        count(set_k, x_k, unsigned) override;
        
        void        count(add_k, const Vector1U&Δ) override;
        void        count(add_k, x_k, unsigned Δx) override;

        void        count(multiply_k, unsigned) override;
        void        count(multiply_k, const Vector1U&Δ) override;
        void        count(multiply_k, x_k, unsigned Δx) override;

        const Vector1U&  count(ref_k) const {  return m_count;  }

        unsigned      x() const { return m_count.x; }

        PCount¹(const ICount¹& i);

    private:
        Vector1U        m_count;
    };
}

