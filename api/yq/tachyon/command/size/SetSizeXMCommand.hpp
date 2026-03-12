////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeˣMCommand, SizeCommand)
    public:
        SetSizeˣMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeˣMCommand(const Header&);
        SetSizeˣMCommand(const SetSizeˣMCommand&, const Header&);
        ~SetSizeˣMCommand();

    private:
        Meter   m_x = 0.;
        
        SetSizeˣMCommand(const SetSizeˣMCommand&) = delete;
        SetSizeˣMCommand(SetSizeˣMCommand&&) = delete;
        SetSizeˣMCommand& operator=(const SetSizeˣMCommand&) = delete;
        SetSizeˣMCommand& operator=(SetSizeˣMCommand&&) = delete;
    };
}
