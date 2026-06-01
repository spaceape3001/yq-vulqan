////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4D.hpp"
#include <yq/tachyon/command/position/AddPosition4DCommand.hpp>
#include <yq/tachyon/command/position/AddPositionWDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYDCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>
#include <yq/tachyon/command/position/SetPosition4DCommand.hpp>
#include <yq/tachyon/command/position/SetPositionWDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYDCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZDCommand.hpp>

namespace yq::tachyon {
    PPosition⁴D::PPosition⁴D(const IPosition⁴D& i) : m_position(i.position())
    {
        if(i.position(DISABLED))
            m_flags |= F::Disabled;
        if(i.position(SETTABLE))
            m_flags |= F::Settable;
        if(i.position(ADDABLE))
            m_flags |= F::Addable;
        if(i.position(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }

    PPosition⁴D::~PPosition⁴D()
    {
    }

    bool        PPosition⁴D::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition⁴D::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition⁴D::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition⁴D::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition⁴D::position(set_k, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition⁴DCommand({.target=object()}, v));
        }
    }

    void        PPosition⁴D::position(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʷDCommand({.target=object()}, w));
        }
    }
    
    void        PPosition⁴D::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣDCommand({.target=object()}, x));
        }
    }
    
    void        PPosition⁴D::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸDCommand({.target=object()}, y));
        }
    }
    
    void        PPosition⁴D::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻDCommand({.target=object()}, z));
        }
    }

    void        PPosition⁴D::position(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴D::position(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʷDCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴D::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴D::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴D::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻDCommand({.target=object()}, Δz));
        }
    }

    void        PPosition⁴D::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴D::position(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴D::position(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʷDCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴D::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴D::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴D::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
