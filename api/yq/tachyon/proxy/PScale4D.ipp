////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PScale4D.hpp"

#include <yq/tachyon/command/scale/AddScale4DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale4DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale4DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleWDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>

namespace yq::tachyon {
    PScale⁴D::PScale⁴D(const IScale⁴D& i) : m_scale(i.scale())
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

    PScale⁴D::~PScale⁴D()
    {
    }

    bool        PScale⁴D::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale⁴D::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale⁴D::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale⁴D::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale⁴D::scale(set_k, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale⁴DCommand({.target=object()}, v));
        }
    }

    void        PScale⁴D::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣDCommand({.target=object()}, x));
        }
    }
    
    void        PScale⁴D::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸDCommand({.target=object()}, y));
        }
    }
    
    void        PScale⁴D::scale(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleᶻDCommand({.target=object()}, z));
        }
    }

    void        PScale⁴D::scale(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʷDCommand({.target=object()}, w));
        }
    }

    void        PScale⁴D::scale(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PScale⁴D::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale⁴D::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸDCommand({.target=object()}, Δy));
        }
    }

    void        PScale⁴D::scale(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PScale⁴D::scale(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʷDCommand({.target=object()}, Δw));
        }
    }

    void        PScale⁴D::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleDCommand({.target=object()}, Δ));
        }
    }

    void        PScale⁴D::scale(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PScale⁴D::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale⁴D::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸDCommand({.target=object()}, Δy));
        }
    }

    void        PScale⁴D::scale(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PScale⁴D::scale(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʷDCommand({.target=object()}, Δw));
        }
    }
}
