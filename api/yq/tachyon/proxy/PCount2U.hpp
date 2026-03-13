////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ICount2U.hpp>

namespace yq::tachyon {
    class PCount²U : public Proxy, public ICount²U  /* TODO: public ICount²UI, public ICount²U, public ICount */ {
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

        PCount²U(const ICount²U& i);
        ~PCount²U();

    private:
        const Vector2U  m_count;
    };
}

