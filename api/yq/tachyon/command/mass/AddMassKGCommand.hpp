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
    class AddMassKGCommand : public MassCommand {
        YQ_OBJECT_DECLARE(AddMassKGCommand, MassCommand)
    public:
        AddMassKGCommand(const Header&, Kilogram);
        
        static void init_meta();
        
        Kilogram Δmass() const { return m_Δmass; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMassKGCommand(const AddMassKGCommand&, const Header&);
        ~AddMassKGCommand();
        AddMassKGCommand(const Header&);

    private:
        Kilogram  m_Δmass;
        
        AddMassKGCommand(const AddMassKGCommand&) = delete;
        AddMassKGCommand(AddMassKGCommand&&) = delete;
        AddMassKGCommand& operator=(const AddMassKGCommand&) = delete;
        AddMassKGCommand& operator=(AddMassKGCommand&&) = delete;
    };
}
