////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PScale2.hpp>
#include <yq/tachyon/command/scale/AddScale2Command.hpp>
#include <yq/tachyon/command/scale/AddScaleXCommand.hpp>
#include <yq/tachyon/command/scale/AddScaleYCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScale2Command.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleXCommand.hpp>
#include <yq/tachyon/command/scale/MultiplyScaleYCommand.hpp>
#include <yq/tachyon/command/scale/SetScale2Command.hpp>
#include <yq/tachyon/command/scale/SetScaleXCommand.hpp>
#include <yq/tachyon/command/scale/SetScaleYCommand.hpp>

namespace yq::tachyon {
    PScale²::PScale²(const IScale²& i) : m_scale(i.scale())
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

    PScale²::~PScale²()
    {
    }

    bool        PScale²::scale(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PScale²::scale(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PScale²::scale(addable_k) const 
    {
        return m_flags(F::Addable);
    }
    
    bool        PScale²::scale(multipliable_k) const 
    {
        return m_flags(F::Multipliable);
    }
        
    void        PScale²::scale(set_k, const Vector2D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScale²Command({.target=object()}, v));
        }
    }

    void        PScale²::scale(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleˣCommand({.target=object()}, x));
        }
    }
    
    void        PScale²::scale(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetScaleʸCommand({.target=object()}, y));
        }
    }

    void        PScale²::scale(add_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScale²Command({.target=object()}, Δ));
        }
    }

    void        PScale²::scale(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleˣCommand({.target=object()}, Δx));
        }
    }

    void        PScale²::scale(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddScaleʸCommand({.target=object()}, Δy));
        }
    }

    void        PScale²::scale(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleCommand({.target=object()}, Δ));
        }
    }

    void        PScale²::scale(multiply_k, const Vector2D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScale²Command({.target=object()}, Δ));
        }
    }

    void        PScale²::scale(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleˣCommand({.target=object()}, Δx));
        }
    }

    void        PScale²::scale(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyScaleʸCommand({.target=object()}, Δy));
        }
    }
}
