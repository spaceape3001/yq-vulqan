////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size3.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/IMaxSize3D.hpp>

namespace yq::tachyon {
    class PMaxSize³D : public Proxy, public IMaxSize³D {
    public:
    
        using IMaxSize³D::max_size;
    
        //!  Basic max_size in the 3I space
        Size3D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size3D&) override;
        void        max_size(set_k, x_k, double) override;
        void        max_size(set_k, y_k, double) override;
        void        max_size(set_k, z_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Size3D&) override;
        void        max_size(add_k, x_k, double) override;
        void        max_size(add_k, y_k, double) override;
        void        max_size(add_k, z_k, double) override;

        void        max_size(multiply_k, double) override;
        void        max_size(multiply_k, const Vector3D&) override;
        void        max_size(multiply_k, x_k, double) override;
        void        max_size(multiply_k, y_k, double) override;
        void        max_size(multiply_k, z_k, double) override;
        
        bool        max_size(disabled_k) const override;
        bool        max_size(settable_k) const override;
        bool        max_size(addable_k) const override;
        bool        max_size(multipliable_k) const override;
        
        const Size3D&   max_size(ref_k) const { return m_max_size; }

        PMaxSize³D(const IMaxSize³D& i);
        virtual ~PMaxSize³D();

    private:
        Size3D const  m_max_size;
    };
}

