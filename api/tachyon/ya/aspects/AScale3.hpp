////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IScale3.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale³;
    class AddScaleˣ;
    class AddScaleʸ;
    class AddScaleᶻ;
    class MultiplyScale;
    class MultiplyScale³;
    class MultiplyScaleˣ;
    class MultiplyScaleʸ;
    class MultiplyScaleᶻ;
    class SetScale³;
    class SetScaleˣ;
    class SetScaleʸ;
    class SetScaleᶻ;

    class AScale³ : public IScale³, public virtual Tachyon::Helper {
    public:
    
        //!  Basic scale in the 3D space
        Vector3D        scale() const override { return m_scale; }

        double          scale(x_k) const { return m_scale.x; }
        double          scale(y_k) const { return m_scale.y; }
        double          scale(z_k) const { return m_scale.z; }
        
        //!  Set scale the scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    scale(set_k, const Vector3D&) override;
        void            scale(set_k, x_k, double) override;
        void            scale(set_k, y_k, double) override;
        void            scale(set_k, z_k, double) override;
        
        //!  Move the scale (ie set to scale + delta)
        void            scale(add_k, const Vector3D&) override;
        void            scale(add_k, x_k, double) override;
        void            scale(add_k, y_k, double) override;
        void            scale(add_k, z_k, double) override;

        void            scale(multiply_k, double) override;
        void            scale(multiply_k, const Vector3D&) override;
        void            scale(multiply_k, x_k, double) override;
        void            scale(multiply_k, y_k, double) override;
        void            scale(multiply_k, z_k, double) override;
        
        bool            scale(disabled_k) const { return false; }
        bool            scale(settable_k) const { return true; }
        bool            scale(addable_k) const { return true; }
        bool            scale(multipliable_k) const { return true; }

        const Vector3D& scale(ref_k) const { return m_scale; }

    protected:
        
        Vector3D        m_scale = ONE;

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AScale³();
        virtual ~AScale³();

        void            scale(emit_k);
        
    private:
        void        on_set_scale3(const SetScale³&);
        void        on_set_scaleX(const SetScaleˣ&);
        void        on_set_scaleY(const SetScaleʸ&);
        void        on_set_scaleZ(const SetScaleᶻ&);

        void        on_add_scale3(const AddScale³&);
        void        on_add_scaleX(const AddScaleˣ&);
        void        on_add_scaleY(const AddScaleʸ&);
        void        on_add_scaleZ(const AddScaleᶻ&);
        
        void        on_multiply_scale(const MultiplyScale&);
        void        on_multiply_scale3(const MultiplyScale³&);
        void        on_multiply_scaleX(const MultiplyScaleˣ&);
        void        on_multiply_scaleY(const MultiplyScaleʸ&);
        void        on_multiply_scaleZ(const MultiplyScaleᶻ&);
    };

}
