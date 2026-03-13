////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IScale4D.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale⁴DCommand;
    class AddScaleʷDCommand;
    class AddScaleˣDCommand;
    class AddScaleʸDCommand;
    class AddScaleᶻDCommand;
    class MultiplyScaleDCommand;
    class MultiplyScale⁴DCommand;
    class MultiplyScaleʷDCommand;
    class MultiplyScaleˣDCommand;
    class MultiplyScaleʸDCommand;
    class MultiplyScaleᶻDCommand;
    class SetScale⁴DCommand;
    class SetScaleʷDCommand;
    class SetScaleˣDCommand;
    class SetScaleʸDCommand;
    class SetScaleᶻDCommand;

    class AScale⁴D : public IScale⁴D, public virtual Tachyon::Helper {
    public:
    
        struct Param {
            Vector4D    scale   = ONE;
        };
    
        //!  Basic scale in the 4D space
        Vector4D        scale() const override { return m_scale; }

        double          scale(w_k) const { return m_scale.w; }
        double          scale(x_k) const { return m_scale.x; }
        double          scale(y_k) const { return m_scale.y; }
        double          scale(z_k) const { return m_scale.z; }
        
        //!  Set scale the scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    scale(set_k, const Vector4D&) override;
        void            scale(set_k, x_k, double) override;
        void            scale(set_k, y_k, double) override;
        void            scale(set_k, z_k, double) override;
        void            scale(set_k, w_k, double) override;
        
        //!  Move the scale (ie set to scale + delta)
        void            scale(add_k, const Vector4D&) override;
        void            scale(add_k, x_k, double) override;
        void            scale(add_k, y_k, double) override;
        void            scale(add_k, z_k, double) override;
        void            scale(add_k, w_k, double) override;

        void            scale(multiply_k, double) override;
        void            scale(multiply_k, const Vector4D&) override;
        void            scale(multiply_k, x_k, double) override;
        void            scale(multiply_k, y_k, double) override;
        void            scale(multiply_k, z_k, double) override;
        void            scale(multiply_k, w_k, double) override;
        
        bool            scale(disabled_k) const { return false; }
        bool            scale(settable_k) const { return true; }
        bool            scale(addable_k) const { return true; }
        bool            scale(multipliable_k) const { return true; }

        const Vector4D& scale(ref_k) const { return m_scale; }

    protected:
        
        Vector4D        m_scale = ONE;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AScale⁴D(const Vector4D& sca=ONE);
        AScale⁴D(const Param&);
        virtual ~AScale⁴D();

        void            scale(emit_k);
        
    private:
        void        on_set_scale4(const SetScale⁴DCommand&);
        void        on_set_scaleW(const SetScaleʷDCommand&);
        void        on_set_scaleX(const SetScaleˣDCommand&);
        void        on_set_scaleY(const SetScaleʸDCommand&);
        void        on_set_scaleZ(const SetScaleᶻDCommand&);

        void        on_add_scale4(const AddScale⁴DCommand&);
        void        on_add_scaleW(const AddScaleʷDCommand&);
        void        on_add_scaleX(const AddScaleˣDCommand&);
        void        on_add_scaleY(const AddScaleʸDCommand&);
        void        on_add_scaleZ(const AddScaleᶻDCommand&);
        
        void        on_multiply_scale(const MultiplyScaleDCommand&);
        void        on_multiply_scale4(const MultiplyScale⁴DCommand&);
        void        on_multiply_scaleW(const MultiplyScaleʷDCommand&);
        void        on_multiply_scaleX(const MultiplyScaleˣDCommand&);
        void        on_multiply_scaleY(const MultiplyScaleʸDCommand&);
        void        on_multiply_scaleZ(const MultiplyScaleᶻDCommand&);
    };

}
