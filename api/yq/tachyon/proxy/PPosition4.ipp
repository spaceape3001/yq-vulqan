////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/proxy/PPosition4.hpp>
#include <yq/tachyon/command/position/AddPosition4Command.hpp>
#include <yq/tachyon/command/position/AddPositionWCommand.hpp>
#include <yq/tachyon/command/position/AddPositionXCommand.hpp>
#include <yq/tachyon/command/position/AddPositionYCommand.hpp>
#include <yq/tachyon/command/position/AddPositionZCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4Command.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZCommand.hpp>
#include <yq/tachyon/command/position/SetPosition4Command.hpp>
#include <yq/tachyon/command/position/SetPositionWCommand.hpp>
#include <yq/tachyon/command/position/SetPositionXCommand.hpp>
#include <yq/tachyon/command/position/SetPositionYCommand.hpp>
#include <yq/tachyon/command/position/SetPositionZCommand.hpp>

namespace yq::tachyon {
    PPosition⁴::PPosition⁴(const IPosition⁴& i) : m_position(i.position())
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

    PPosition⁴::~PPosition⁴()
    {
    }

    bool        PPosition⁴::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition⁴::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition⁴::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition⁴::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition⁴::position(set_k, const Vector4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition⁴Command({.target=object()}, v));
        }
    }

    void        PPosition⁴::position(set_k, w_k, double w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʷCommand({.target=object()}, w));
        }
    }
    
    void        PPosition⁴::position(set_k, x_k, double x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCommand({.target=object()}, x));
        }
    }
    
    void        PPosition⁴::position(set_k, y_k, double y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCommand({.target=object()}, y));
        }
    }
    
    void        PPosition⁴::position(set_k, z_k, double z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻCommand({.target=object()}, z));
        }
    }

    void        PPosition⁴::position(add_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition⁴Command({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(add_k, w_k, double Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʷCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴::position(add_k, x_k, double Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴::position(add_k, y_k, double Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴::position(add_k, z_k, double Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻCommand({.target=object()}, Δz));
        }
    }

    void        PPosition⁴::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition⁴Command({.target=object()}, Δ));
        }
    }

    void        PPosition⁴::position(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʷCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻCommand({.target=object()}, Δz));
        }
    }
}
