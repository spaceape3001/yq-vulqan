////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PMassKG.hpp"
#include <yq/tachyon/command/mass/AddMassKGCommand.hpp>
#include <yq/tachyon/command/mass/MultiplyMassCommand.hpp>
#include <yq/tachyon/command/mass/SetMassKGCommand.hpp>

namespace yq::tachyon {
    PMassKG::PMassKG(const IMassKG&i) : m_mass(i.mass())
    {
        if(i.mass(DISABLED))
            m_flags |= F::Disabled;
        if(i.mass(SETTABLE))
            m_flags |= F::Settable;
        if(i.mass(ADDABLE))
            m_flags |= F::Addable;
        if(i.mass(MULTIPLIABLE))
            m_flags |= F::Multipliable;
    }
    
    PMassKG::~PMassKG() = default;

    bool        PMassKG::mass(disabled_k) const 
    {
        return m_flags(F::Disabled);
    }

    bool        PMassKG::mass(settable_k) const 
    {
        return m_flags(F::Settable);
    }
    
    bool        PMassKG::mass(addable_k) const 
    {
        return m_flags(F::Addable);
    }
        
    bool        PMassKG::mass(multipliable_k) const 
    {
        return m_flags(F::Addable);
    }

    void    PMassKG::mass(add_k, unit::Kilogram Δkg) 
    {
        if(m_flags(F::Addable) && !m_flags(F::Disabled)){
            mail(new AddMassKGCommand({.target=object()}, Δkg));
        }
    }
    
    void    PMassKG::mass(multiply_k, double δ) 
    {
        if(m_flags(F::Multipliable) && !m_flags(F::Disabled)){
            mail(new MultiplyMassCommand({.target=object()}, δ));
        }
    }
    
    void    PMassKG::mass(set_k, unit::Kilogram kg) 
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetMassKGCommand({.target=object()}, kg));
        }
    }
}
