////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3D.hpp>

namespace yq::tachyon {
    class PPosition3D : public Proxy, public IPosition3D  /* TODO: public IPosition3I, public IPosition3, public IPosition */ {
    public:
    
        Vector3D    position3d() const override {  return m_position;  }
        bool        position3d(disabled_k) const override;
        bool        position3d(settable_k) const override;
        bool        position3d(adjustable_k) const override;
        
        void        position3d(set_k, const Vector3D&) override;
        void        position3d(adjust_k, const Vector3D&) override;

        PPosition3D(const IPosition3D& i);
        ~PPosition3D();

    private:
        Vector3D        m_position;
    };
}

