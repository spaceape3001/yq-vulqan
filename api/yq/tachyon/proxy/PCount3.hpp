////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ICount3.hpp>

namespace yq::tachyon {
    class PCount³ : public Proxy, public ICount³  /* TODO: public ICount³I, public ICount³, public ICount */ {
    public:
    
        Vector3U    count() const override {  return m_count;  }
        bool        count(disabled_k) const override;
        bool        count(settable_k) const override;
        bool        count(addable_k) const override;
        bool        count(multipliable_k) const override;
        
        void        count(set_k, const Vector3U&) override;
        void        count(set_k, x_k, unsigned) override;
        void        count(set_k, y_k, unsigned) override;
        void        count(set_k, z_k, unsigned) override;

        void        count(add_k, const Vector3U&Δ) override;
        void        count(add_k, x_k, unsigned Δx) override;
        void        count(add_k, y_k, unsigned Δy) override;
        void        count(add_k, z_k, unsigned Δz) override;

        void        count(multiply_k, unsigned) override;
        void        count(multiply_k, const Vector3U&Δ) override;
        void        count(multiply_k, x_k, unsigned Δx) override;
        void        count(multiply_k, y_k, unsigned Δy) override;
        void        count(multiply_k, z_k, unsigned Δz) override;

        unsigned      x() const { return m_count.x; }
        unsigned      y() const { return m_count.y; }
        unsigned      z() const { return m_count.z; }

        const Vector3U&  count(ref_k) const {  return m_count;  }

        PCount³(const ICount³& i);
        ~PCount³();

    private:
        const Vector3U  m_count;
    };
}

