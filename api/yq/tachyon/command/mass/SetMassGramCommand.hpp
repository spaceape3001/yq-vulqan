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
    class SetMassGramCommand : public MassCommand {
        YQ_OBJECT_DECLARE(SetMassGramCommand, MassCommand)
    public:
        SetMassGramCommand(const Header&, unit::Gram);
        
        static void init_meta();
        
        unit::Gram mass() const { return m_mass; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMassGramCommand(const SetMassGramCommand&, const Header&);
        ~SetMassGramCommand();
        SetMassGramCommand(const Header&);

    private:
        unit::Gram  m_mass;
        
        SetMassGramCommand(const SetMassGramCommand&) = delete;
        SetMassGramCommand(SetMassGramCommand&&) = delete;
        SetMassGramCommand& operator=(const SetMassGramCommand&) = delete;
        SetMassGramCommand& operator=(SetMassGramCommand&&) = delete;
    };
}
