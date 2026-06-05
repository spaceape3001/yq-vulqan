////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PPosition4CM.hpp"
#include <yq/tachyon/command/position/centimeter/AddPosition4CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionWCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/AddPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPosition4CMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionWCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionXCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionYCMCommand.hpp>
#include <yq/tachyon/command/position/centimeter/SetPositionZCMCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPosition4DCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionWDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionXDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionYDCommand.hpp>
#include <yq/tachyon/command/position/MultiplyPositionZDCommand.hpp>

namespace yq::tachyon {
    PPosition⁴CM::PPosition⁴CM(const IPosition⁴CM& i) : m_position(i.position())
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

    PPosition⁴CM::~PPosition⁴CM()
    {
    }

    bool        PPosition⁴CM::position(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }
    
    bool        PPosition⁴CM::position(settable_k) const 
    {   
        return m_flags(F::Settable);
    }
    
    bool        PPosition⁴CM::position(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PPosition⁴CM::position(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void        PPosition⁴CM::position(set_k, const Centimeter4D& v) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPosition⁴CMCommand({.target=object()}, v));
        }
    }

    void        PPosition⁴CM::position(set_k, w_k, Centimeter w) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʷCMCommand({.target=object()}, w));
        }
    }
    
    void        PPosition⁴CM::position(set_k, x_k, Centimeter x) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionˣCMCommand({.target=object()}, x));
        }
    }
    
    void        PPosition⁴CM::position(set_k, y_k, Centimeter y) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionʸCMCommand({.target=object()}, y));
        }
    }
    
    void        PPosition⁴CM::position(set_k, z_k, Centimeter z) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetPositionᶻCMCommand({.target=object()}, z));
        }
    }

    void        PPosition⁴CM::position(add_k, const Centimeter4D& Δ) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPosition⁴CMCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴CM::position(add_k, w_k, Centimeter Δw) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʷCMCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴CM::position(add_k, x_k, Centimeter Δx) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionˣCMCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴CM::position(add_k, y_k, Centimeter Δy) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionʸCMCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴CM::position(add_k, z_k, Centimeter Δz) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddPositionᶻCMCommand({.target=object()}, Δz));
        }
    }

    void        PPosition⁴CM::position(multiply_k, double Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionDCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴CM::position(multiply_k, const Vector4D& Δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPosition⁴DCommand({.target=object()}, Δ));
        }
    }

    void        PPosition⁴CM::position(multiply_k, w_k, double Δw) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʷDCommand({.target=object()}, Δw));
        }
    }

    void        PPosition⁴CM::position(multiply_k, x_k, double Δx) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionˣDCommand({.target=object()}, Δx));
        }
    }

    void        PPosition⁴CM::position(multiply_k, y_k, double Δy) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionʸDCommand({.target=object()}, Δy));
        }
    }

    void        PPosition⁴CM::position(multiply_k, z_k, double Δz) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyPositionᶻDCommand({.target=object()}, Δz));
        }
    }
}
