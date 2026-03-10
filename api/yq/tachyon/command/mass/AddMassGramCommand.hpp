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
    class AddMassGramCommand : public MassCommand {
        YQ_OBJECT_DECLARE(AddMassGramCommand, MassCommand)
    public:
        AddMassGramCommand(const Header&, unit::Gram);
        
        static void init_meta();
        
        unit::Gram Δmass() const { return m_Δmass; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMassGramCommand(const AddMassGramCommand&, const Header&);
        ~AddMassGramCommand();
        AddMassGramCommand(const Header&);

    private:
        unit::Gram  m_Δmass;
        
        AddMassGramCommand(const AddMassGramCommand&) = delete;
        AddMassGramCommand(AddMassGramCommand&&) = delete;
        AddMassGramCommand& operator=(const AddMassGramCommand&) = delete;
        AddMassGramCommand& operator=(AddMassGramCommand&&) = delete;
    };
}
