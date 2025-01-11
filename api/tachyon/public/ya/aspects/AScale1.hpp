////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/interfaces/IScale1.hpp>
#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScale¹;
    class AddScaleˣ;
    class MultiplyScale;
    class MultiplyScale¹;
    class MultiplyScaleˣ;
    class SetScale¹;
    class SetScaleˣ;

    class AScale¹ : public IScale¹, private Tachyon::Helper {
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
        
        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AScale¹();
        virtual ~AScale¹();
        
    private:
        void        on_set_scale1(const SetScale¹&);
        void        on_set_scaleX(const SetScaleˣ&);

        void        on_add_scale1(const AddScale¹&);
        void        on_add_scaleX(const AddScaleˣ&);
        
        void        on_multiply_scale(const MultiplyScale&);
        void        on_multiply_scale1(const MultiplyScale¹&);
        void        on_multiply_scaleX(const MultiplyScaleˣ&);

        Vector1D    m_scale = ONE;
    };

}
