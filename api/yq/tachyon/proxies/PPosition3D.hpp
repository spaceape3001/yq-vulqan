////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interfaces/IPosition3D.hpp>

namespace yq::tachyon {
    class PPosition3D : public Proxy, public IPosition3D {
    public:
    
        Vector3D    position3d() const override {  return m_position;  }
        
        void        position3d(set_t, const Vector3D&) override;
        void        position3d(move_t, const Vector3D&) override;

    private:
        PPosition3D(Tachyon* t, IPosition3D& i);
        PPosition3D(Tachyon* t, IPosition3D& i, const Vector3D& p, uint64_t rev=0);

        IPosition3D&    m_interface;
        Vector3D        m_position;

        virtual Proxy*    reproxy() const override;
    };
}

