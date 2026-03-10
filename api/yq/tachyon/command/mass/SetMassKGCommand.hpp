////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/MassCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetMassKGCommand : public MassCommand {
        YQ_OBJECT_DECLARE(SetMassKGCommand, MassCommand)
    public:
        SetMassKGCommand(const Header&, unit::Kilogram);
        
        static void init_meta();
        
        unit::Kilogram mass() const { return m_mass; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMassKGCommand(const SetMassKGCommand&, const Header&);
        ~SetMassKGCommand();
        SetMassKGCommand(const Header&);

    private:
        unit::Kilogram  m_mass;
        
        SetMassKGCommand(const SetMassKGCommand&) = delete;
        SetMassKGCommand(SetMassKGCommand&&) = delete;
        SetMassKGCommand& operator=(const SetMassKGCommand&) = delete;
        SetMassKGCommand& operator=(SetMassKGCommand&&) = delete;
    };
}
