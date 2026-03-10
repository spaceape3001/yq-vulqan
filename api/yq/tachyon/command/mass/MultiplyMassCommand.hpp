////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/MassCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMassCommand : public MassCommand {
        YQ_OBJECT_DECLARE(MultiplyMassCommand, MassCommand)
    public:
        MultiplyMassCommand(const Header&, double δmass);
        
        static void init_meta();
        
        double δmass() const { return m_δmass; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMassCommand(const MultiplyMassCommand&, const Header&);
        ~MultiplyMassCommand();
        MultiplyMassCommand(const Header&);

    private:
        double  m_δmass;
        
        MultiplyMassCommand(const MultiplyMassCommand&) = delete;
        MultiplyMassCommand(MultiplyMassCommand&&) = delete;
        MultiplyMassCommand& operator=(const MultiplyMassCommand&) = delete;
        MultiplyMassCommand& operator=(MultiplyMassCommand&&) = delete;
    };
}
