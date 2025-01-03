////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/ISize2I.hpp>

namespace yq::tachyon {
    class PSize2I : public Proxy, public ISize2I {
    public:
    
        Size2I      size2i() const override {  return m_size;  }
        bool        size2i(disabled_k) const override;
        bool        size2i(settable_k) const override;
        bool        size2i(adjustable_k) const override;
        
        void        size2i(adjust_k, const Size2I&) override;
        void        size2i(move_t, const Size2I&) override;

        PSize2I(const ISize2I& i);

    private:
        Size2I        m_size;
    };
}

