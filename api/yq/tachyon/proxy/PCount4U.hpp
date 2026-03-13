////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ICount4U.hpp>

namespace yq::tachyon {
    class PCount⁴U : public Proxy, public ICount⁴U  /* TODO: public ICount⁴UI, public ICount⁴U, public ICount */ {
    public:
    
        Vector4U    count() const override {  return m_count;  }
        bool        count(disabled_k) const override;
        bool        count(settable_k) const override;
        bool        count(addable_k) const override;
        bool        count(multipliable_k) const override;
        
        void        count(set_k, const Vector4U&) override;
        void        count(set_k, x_k, unsigned) override;
        void        count(set_k, y_k, unsigned) override;
        void        count(set_k, z_k, unsigned) override;
        void        count(set_k, w_k, unsigned) override;

        void        count(add_k, const Vector4U&Δ) override;
        void        count(add_k, x_k, unsigned Δx) override;
        void        count(add_k, y_k, unsigned Δy) override;
        void        count(add_k, z_k, unsigned Δz) override;
        void        count(add_k, w_k, unsigned Δw) override;

        void        count(multiply_k, unsigned) override;
        void        count(multiply_k, const Vector4U&Δ) override;
        void        count(multiply_k, x_k, unsigned Δx) override;
        void        count(multiply_k, y_k, unsigned Δy) override;
        void        count(multiply_k, z_k, unsigned Δz) override;
        void        count(multiply_k, w_k, unsigned Δw) override;

        unsigned      x() const { return m_count.x; }
        unsigned      y() const { return m_count.y; }
        unsigned      z() const { return m_count.z; }
        unsigned      w() const { return m_count.w; }

        const Vector4U&  count(ref_k) const {  return m_count;  }

        PCount⁴U(const ICount⁴U& i);
        ~PCount⁴U();

    private:
        const Vector4U  m_count;
    };
}

