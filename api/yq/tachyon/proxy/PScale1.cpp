////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PScale1.hpp>
#include <yq/tachyon/command/scale/AddScale1DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale1DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale1DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>

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
            mail(new SetScale¹DCommand({.target=object()}, v));
        }
    }

    void        PScale¹::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣDCommand({.target=object()}, x));
        }
    }
    
    void        PScale¹::scale(add_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale¹DCommand({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale¹::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleDCommand({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(multiply_k, const Vector1D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale¹DCommand({.target=object()}, Δ));
        }
    }

    void        PScale¹::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣDCommand({.target=object()}, Δx));
        }
    }
}
