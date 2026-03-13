////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IScale3D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale³DCommand;
    class AddScaleˣDCommand;
    class AddScaleʸDCommand;
    class AddScaleᶻDCommand;
    class MultiplyScaleDCommand;
    class MultiplyScale³DCommand;
    class MultiplyScaleˣDCommand;
    class MultiplyScaleʸDCommand;
    class MultiplyScaleᶻDCommand;
    class SetScale³DCommand;
    class SetScaleˣDCommand;
    class SetScaleʸDCommand;
    class SetScaleᶻDCommand;

    class AScale³D : public IScale³D, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector3D    scale   = ONE;
        };
    
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
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AScale³D(const Vector3D& sca=ONE);
        AScale³D(const Param&);
        virtual ~AScale³D();

        void            scale(emit_k);
        
    private:
        void        on_set_scale3(const SetScale³DCommand&);
        void        on_set_scaleX(const SetScaleˣDCommand&);
        void        on_set_scaleY(const SetScaleʸDCommand&);
        void        on_set_scaleZ(const SetScaleᶻDCommand&);

        void        on_add_scale3(const AddScale³DCommand&);
        void        on_add_scaleX(const AddScaleˣDCommand&);
        void        on_add_scaleY(const AddScaleʸDCommand&);
        void        on_add_scaleZ(const AddScaleᶻDCommand&);
        
        void        on_multiply_scale(const MultiplyScaleDCommand&);
        void        on_multiply_scale3(const MultiplyScale³DCommand&);
        void        on_multiply_scaleX(const MultiplyScaleˣDCommand&);
        void        on_multiply_scaleY(const MultiplyScaleʸDCommand&);
        void        on_multiply_scaleZ(const MultiplyScaleᶻDCommand&);
    };

}
