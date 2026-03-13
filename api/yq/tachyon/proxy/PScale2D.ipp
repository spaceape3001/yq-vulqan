////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PScale2D.hpp"

#include <yq/tachyon/command/scale/AddScale2DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale2DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale2DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>

namespace yq::tachyon {
    PScale²D::PScale²D(const IScale²D& i) : m_scale(i.scale())
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

    PScale²D::~PScale²D()
    {
    }

    bool        PScale²D::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale²D::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale²D::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale²D::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale²D::scale(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale²DCommand({.target=object()}, v));
        }
    }

    void        PScale²D::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣDCommand({.target=object()}, x));
        }
    }
    
    void        PScale²D::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸDCommand({.target=object()}, y));
        }
    }

    void        PScale²D::scale(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale²DCommand({.target=object()}, Δ));
        }
    }

    void        PScale²D::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale²D::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸDCommand({.target=object()}, Δy));
        }
    }

    void        PScale²D::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleDCommand({.target=object()}, Δ));
        }
    }

    void        PScale²D::scale(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale²DCommand({.target=object()}, Δ));
        }
    }

    void        PScale²D::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale²D::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸDCommand({.target=object()}, Δy));
        }
    }
}
