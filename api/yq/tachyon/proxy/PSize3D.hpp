////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size3.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ISize3D.hpp>

namespace yq::tachyon {
    class PSize³D : public Proxy, public ISize³D {
    public:
    
        using ISize³D::size;
    
        //!  Basic size in the 3I space
        Size3D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size3D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        void        size(set_k, z_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Size3D&) override;
        void        size(add_k, x_k, double) override;
        void        size(add_k, y_k, double) override;
        void        size(add_k, z_k, double) override;

        void        size(multiply_k, double) override;
        void        size(multiply_k, const Vector3D&) override;
        void        size(multiply_k, x_k, double) override;
        void        size(multiply_k, y_k, double) override;
        void        size(multiply_k, z_k, double) override;
        
        bool        size(disabled_k) const override;
        bool        size(settable_k) const override;
        bool        size(addable_k) const override;
        bool        size(multipliable_k) const override;
        
        const Size3D&   size(ref_k) const { return m_size; }

        PSize³D(const ISize³D& i);
        virtual ~PSize³D();

    private:
        Size3D        m_size;
    };
}

