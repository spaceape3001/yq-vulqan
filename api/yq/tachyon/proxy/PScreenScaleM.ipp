////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PScreenScaleM.hpp"

#include <yq/tachyon/command/scale/AddScaleMCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleMCommand.hpp>

namespace yq::tachyon {
    PScreenScaleM::PScreenScaleM(const IScreenScaleM& i) : m_screenScale(i.screen_scale())
    {
        if(i.screen_scale(DISABLED))
            m_flags |= F::Disabled;
        if(i.screen_scale(SETTABLE))
            m_flags |= F::Settable;
        if(i.screen_scale(ADDABLE))
            m_flags |= F::Addable;
        if(i.screen_scale(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PScreenScaleM::~PScreenScaleM()
    {
    }

    bool        PScreenScaleM::screen_scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScreenScaleM::screen_scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScreenScaleM::screen_scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScreenScaleM::screen_scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScreenScaleM::screen_scale(set_k, Meter v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleMCommand({.target=object()}, v));
        }
    }

    void        PScreenScaleM::screen_scale(add_k, Meter Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleMCommand({.target=object()}, Δ));
        }
    }

    void        PScreenScaleM::screen_scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleDCommand({.target=object()}, Δ));
        }
    }
}
