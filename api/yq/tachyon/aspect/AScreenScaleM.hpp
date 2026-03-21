////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/interface/IScreenScaleM.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class AddScaleMCommand;
    class MultiplyScaleDCommand;
    class SetScaleMCommand;
    
    struct ScreenScaleSnap;

    class AScreenScaleM : public IScreenScaleM, public virtual Tachyon::Helper {
    public:
    
        //!  Basic screen_scale in the 1D space
        Meter           screen_scale() const override { return m_screenScale; }

        //!  Set screen_scale the screen_scale (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    screen_scale(set_k, Meter) override;
        
        //!  Move the screen_scale (ie set to screen_scale + delta)
        void            screen_scale(add_k, Meter) override;

        void            screen_scale(multiply_k, double) override;
        bool            screen_scale(disabled_k) const { return false; }
        bool            screen_scale(settable_k) const { return true; }
        bool            screen_scale(addable_k) const { return true; }
        bool            screen_scale(multipliable_k) const { return true; }

        const Meter&    screen_scale(ref_k) const { return m_screenScale; }

    protected:
        
        Meter           m_screenScale = 1._m;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        AScreenScaleM();
        virtual ~AScreenScaleM();
        
        void            screen_scale(emit_k);
        
        void            snap(ScreenScaleSnap&) const;
        
    private:
        void        on_set_scale(const SetScaleMCommand&);
        void        on_add_scale(const AddScaleMCommand&);
        void        on_multiply_scale(const MultiplyScaleDCommand&);
    };

}
