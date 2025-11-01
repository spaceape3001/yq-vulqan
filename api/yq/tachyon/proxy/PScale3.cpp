////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PScale3.hpp>
#include <yq/tachyon/command/scale/AddScale3Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleZCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale3Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleZCommand.hpp>
#include <yq/tachyon/command/scale/SetScale3Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleZCommand.hpp>

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
            mail(new SetScale³Command({.target=object()}, v));
        }
    }

    void        PScale³::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣCommand({.target=object()}, x));
        }
    }
    
    void        PScale³::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸCommand({.target=object()}, y));
        }
    }
    
    void        PScale³::scale(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleᶻCommand({.target=object()}, z));
        }
    }

    void        PScale³::scale(add_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale³Command({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣCommand({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸCommand({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleᶻCommand({.target=object()}, Δz));
        }
    }

    void        PScale³::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleCommand({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(multiply_k, const Vector3D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale³Command({.target=object()}, Δ));
        }
    }

    void        PScale³::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣCommand({.target=object()}, Δx));
        }
    }

    void        PScale³::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸCommand({.target=object()}, Δy));
        }
    }

    void        PScale³::scale(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleᶻCommand({.target=object()}, Δz));
        }
    }
}
