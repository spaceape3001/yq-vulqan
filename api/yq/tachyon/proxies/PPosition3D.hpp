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
    
        Vector3D    position3d() const override {  m_position;  }
        
        void        position3d(set_t, const Vector3D&) override;
        void        position3d(move_t, const Vector3D&) override;

    private:
        PPosition3D(Tachyon* t, IPosition3D& i, const Vector3D& p=i.position3d(), uint64_t rev=0);

        IPosition3D&    m_interface;
        Vector3D        m_position;

        virtual Proxy*    reproxy() const override
        {
            Vector3D        pos = m_interface.position3d();
            if(m_position != pos)
                return new PPosition3D(object(), m_interface, pos, revision()+1);
            return nullptr;
        }
    };
}

YQ_PROXY_DECLARE(yq::tachyon::PPosition3D)
