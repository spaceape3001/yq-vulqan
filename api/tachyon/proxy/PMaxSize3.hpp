////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Proxy.hpp>
#include <tachyon/interface/IMaxSize3.hpp>

namespace yq::tachyon {
    class PMaxSize³ : public Proxy, public IMaxSize³ {
    public:
    
        //!  Basic max_size in the 3I space
        Size3D      max_size() const { return m_max_size; }
        
        //!  Set max_size the max_size
        void        max_size(set_k, const Size3D&) override;
        void        max_size(set_k, x_k, double) override;
        void        max_size(set_k, y_k, double) override;
        void        max_size(set_k, z_k, double) override;
        
        //!  Move the max_size (ie set to max_size + delta)
        void        max_size(add_k, const Vector3D&) override;
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

        PMaxSize³(const IMaxSize³& i);
        virtual ~PMaxSize³();

    private:
        Size3D        m_max_size;
    };
}

