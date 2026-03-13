////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PScale3.hpp>
#include <yq/tachyon/command/scale/AddScale3DCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3DCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZDCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3DCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleXDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYDCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZDCommand.hpp>

namespace yq::tachyon {
    PScale³::PScale³(const IScale³& i) : m_scale(i.scale())
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

    PScale³::~PScale³()
    {
    }

    bool        PScale³::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale³::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale³::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale³::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale³::scale(set_k, const Vector3D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale³DCommand({.target=object()}, v));
        }
    }

    void        PScale³::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣDCommand({.target=object()}, x));
        }
    }
    
    void        PScale³::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸDCommand({.target=object()}, y));
        }
    }
    
    void        PScale³::scale(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleᶻDCommand({.target=object()}, z));
        }
    }

    void        PScale³::scale(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale³DCommand({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸDCommand({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PScale³::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleDCommand({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale³DCommand({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣDCommand({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸDCommand({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleᶻDCommand({.target=object()}, Δz));
        }
    }
}
