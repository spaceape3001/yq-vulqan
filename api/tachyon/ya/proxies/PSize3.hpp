////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <ya/interfaces/ISize3.hpp>

namespace yq::tachyon {
    class PSize³ : public Proxy, public ISize³ {
    public:
    
        //!  Basic size in the 3I space
        Size3D      size() const { return m_size; }
        
        //!  Set size the size
        void        size(set_k, const Size3D&) override;
        void        size(set_k, x_k, double) override;
        void        size(set_k, y_k, double) override;
        void        size(set_k, z_k, double) override;
        
        //!  Move the size (ie set to size + delta)
        void        size(add_k, const Vector3D&) override;
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

        PSize³(const ISize³& i);
        virtual ~PSize³();

    private:
        Size3D        m_size;
    };
}

