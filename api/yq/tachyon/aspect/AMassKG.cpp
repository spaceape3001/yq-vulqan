////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AMassKG.hpp"
#include <yq/tachyon/command/mass/AddMassKGCommand.hpp>
#include <yq/tachyon/command/mass/MultiplyMassCommand.hpp>
#include <yq/tachyon/command/mass/SetMassKGCommand.hpp>
#include <yq/tachyon/event/MassKGEvent.hpp>

namespace yq::tachyon {
    AMassKG::AMassKG(const Param& p) : m_mass(p.mass)
    {
    }
    
    AMassKG::AMassKG(Kilogram kg) : m_mass(kg)
    {
    }
    
    AMassKG::~AMassKG()
    {
    }

    void    AMassKG::mass(emit_k)
    {
        send(new MassKGEvent({.source=typed()}, m_mass));
    }

    void    AMassKG::mass(add_k, Kilogram kg)
    {
        m_mass += kg;
        mass(EMIT);
    }
    
    void    AMassKG::mass(multiply_k, double d)
    {
        m_mass *= d;
        mass(EMIT);
    }
    
    void    AMassKG::mass(set_k, Kilogram kg)
    {
        m_mass = kg;
        mass(EMIT);
    }

    void AMassKG::on_add_mass_command(const AddMassKGCommand& cmd)
    {
        mass(ADD, cmd.Δmass());
    }
    
    void AMassKG::on_multiply_mass_command(const MultiplyMassCommand&cmd)
    {
        mass(MULTIPLY, cmd.δmass());
    }

    void AMassKG::on_set_mass_command(const SetMassKGCommand&cmd)
    {
        mass(SET, cmd.mass());
    }
    
}
