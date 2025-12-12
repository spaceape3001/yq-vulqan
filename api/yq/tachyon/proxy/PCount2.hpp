////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ICount2.hpp>

namespace yq::tachyon {
    class PCount² : public Proxy, public ICount²  /* TODO: public ICount²I, public ICount², public ICount */ {
    public:
    
        Vector2U    count() const override {  return m_count;  }
        bool        count(disabled_k) const override;
        bool        count(settable_k) const override;
        bool        count(addable_k) const override;
        bool        count(multipliable_k) const override;
        
        void        count(set_k, const Vector2U&) override;
        void        count(set_k, x_k, unsigned) override;
        void        count(set_k, y_k, unsigned) override;
        
        void        count(add_k, const Vector2U&Δ) override;
        void        count(add_k, x_k, unsigned Δx) override;
        void        count(add_k, y_k, unsigned Δy) override;

        void        count(multiply_k, unsigned) override;
        void        count(multiply_k, const Vector2U&Δ) override;
        void        count(multiply_k, x_k, unsigned Δx) override;
        void        count(multiply_k, y_k, unsigned Δy) override;

        const Vector2U&  count(ref_k) const {  return m_count;  }

        unsigned      x() const { return m_count.x; }
        unsigned      y() const { return m_count.y; }

        PCount²(const ICount²& i);

    private:
        const Vector2U  m_count;
    };
}

