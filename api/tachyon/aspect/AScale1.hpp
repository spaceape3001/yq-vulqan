////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IScale1.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale¹Command;
    class AddScaleˣCommand;
    class MultiplyScaleCommand;
    class MultiplyScale¹Command;
    class MultiplyScaleˣCommand;
    class SetScale¹Command;
    class SetScaleˣCommand;

    class AScale¹ : public IScale¹, public virtual Tachyon::Helper {
    public:
    
        //!  Basic scale in the 1D space
        Vector1D        scale() const override { return m_scale; }

        double          scale(x_k) const { return m_scale.x; }
        
        //!  Set scale the scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    scale(set_k, const Vector1D&) override;
        void            scale(set_k, x_k, double) override;
        
        //!  Move the scale (ie set to scale + delta)
        void            scale(add_k, const Vector1D&) override;
        void            scale(add_k, x_k, double) override;

        void            scale(multiply_k, double) override;
        void            scale(multiply_k, const Vector1D&) override;
        void            scale(multiply_k, x_k, double) override;
        
        bool            scale(disabled_k) const { return false; }
        bool            scale(settable_k) const { return true; }
        bool            scale(addable_k) const { return true; }
        bool            scale(multipliable_k) const { return true; }

        const Vector1D& scale(ref_k) const { return m_scale; }

    protected:
        
        Vector1D    m_scale = ONE;

        template <typename C>
        static void init_info(TachyonMeta::Writer<C>&);
        
        AScale¹();
        virtual ~AScale¹();
        
        void            scale(emit_k);
        
    private:
        void        on_set_scale1(const SetScale¹Command&);
        void        on_set_scaleX(const SetScaleˣCommand&);

        void        on_add_scale1(const AddScale¹Command&);
        void        on_add_scaleX(const AddScaleˣCommand&);
        
        void        on_multiply_scale(const MultiplyScaleCommand&);
        void        on_multiply_scale1(const MultiplyScale¹Command&);
        void        on_multiply_scaleX(const MultiplyScaleˣCommand&);

    };

}
