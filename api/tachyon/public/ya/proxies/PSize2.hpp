////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/ISize2.hpp>

namespace yq::tachyon {
    class PSize² : public Proxy, public ISize² {
    public:
    
        Size2I      size() const override {  return m_size;  }
        bool        size(disabled_k) const override;
        bool        size(settable_k) const override;
        bool        size(adjustable_k) const override;
        
        void        size(adjust_k, const Size2I&) override;
        void        size(move_t, const Size2I&) override;

        PSize²(const ISize²& i);

    private:
        Size2I        m_size;
    };
}

