////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PScale1.hpp>
#include <yq/tachyon/command/scale/AddScale1Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale1Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScale1Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>

namespace yq::tachyon {
    PScale¹::PScale¹(const IScale¹& i) : m_scale(i.scale())
    {
        if(i.scale(DISABLED))
            m_flags |= F::Disabled;
        if(i.scale(SETTABLE))
            m_flags |= F::Settable;
        if(i.scale(ADDABLE))
            m_flags |= F::Addable;
        if(i.scale(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PScale¹::~PScale¹()
    {
    }

    bool        PScale¹::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale¹::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale¹::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale¹::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale¹::scale(set_k, const Vector1D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale¹Command({.target=object()}, v));
        }
    }

    void        PScale¹::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣCommand({.target=object()}, x));
        }
    }
    
    void        PScale¹::scale(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale¹Command({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣCommand({.target=object()}, Δx));
        }
    }

    void        PScale¹::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleCommand({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale¹Command({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣCommand({.target=object()}, Δx));
        }
    }
}
