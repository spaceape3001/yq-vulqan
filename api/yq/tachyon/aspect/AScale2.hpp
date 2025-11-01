////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IScale2.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale²Command;
    class AddScaleˣCommand;
    class AddScaleʸCommand;
    class MultiplyScaleCommand;
    class MultiplyScale²Command;
    class MultiplyScaleˣCommand;
    class MultiplyScaleʸCommand;
    class SetScale²Command;
    class SetScaleˣCommand;
    class SetScaleʸCommand;

    class AScale² : public IScale², public virtual Tachyon::Helper {
    public:
    
        //!  Basic scale in the 2D space
        Vector2D        scale() const override { return m_scale; }
        
        double          scale(x_k) const { return m_scale.x; }
        double          scale(y_k) const { return m_scale.y; }

        //!  Set scale the scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    scale(set_k, const Vector2D&) override;
        void            scale(set_k, x_k, double) override;
        void            scale(set_k, y_k, double) override;
        
        //!  Move the scale (ie set to scale + delta)
        void            scale(add_k, const Vector2D&) override;
        void            scale(add_k, x_k, double) override;
        void            scale(add_k, y_k, double) override;

        void            scale(multiply_k, double) override;
        void            scale(multiply_k, const Vector2D&) override;
        void            scale(multiply_k, x_k, double) override;
        void            scale(multiply_k, y_k, double) override;
        
        bool            scale(disabled_k) const { return false; }
        bool            scale(settable_k) const { return true; }
        bool            scale(addable_k) const { return true; }
        bool            scale(multipliable_k) const { return true; }

        const Vector2D& scale(ref_k) const { return m_scale; }

    protected:
        
        Vector2D    m_scale = ONE;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AScale²();
        virtual ~AScale²();

        void            scale(emit_k);
        
    private:
        void        on_set_scale2(const SetScale²Command&);
        void        on_set_scaleX(const SetScaleˣCommand&);
        void        on_set_scaleY(const SetScaleʸCommand&);

        void        on_add_scale2(const AddScale²Command&);
        void        on_add_scaleX(const AddScaleˣCommand&);
        void        on_add_scaleY(const AddScaleʸCommand&);
        
        void        on_multiply_scale(const MultiplyScaleCommand&);
        void        on_multiply_scale2(const MultiplyScale²Command&);
        void        on_multiply_scaleX(const MultiplyScaleˣCommand&);
        void        on_multiply_scaleY(const MultiplyScaleʸCommand&);
    };

}
