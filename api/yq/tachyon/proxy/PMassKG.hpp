////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMassKG.hpp>

namespace yq::tachyon {
    class PMassKG : public Proxy, public IMassKG {
    public:
    
        unit::Kilogram  mass() const override { return m_mass; }
        void    mass(add_k, unit::Kilogram) override;
        void    mass(multiply_k, double) override;
        void    mass(set_k, unit::Kilogram) override;

        bool    mass(disabled_k) const override;
        bool    mass(settable_k) const override;
        bool    mass(addable_k) const override;
        bool    mass(multipliable_k) const override;

        PMassKG(const IMassKG&);
        ~PMassKG();
    private:
        const unit::Kilogram    m_mass;
    };
}
