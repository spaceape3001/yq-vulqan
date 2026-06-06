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
    class SetMaxSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeˣMCommand, SizeCommand)
    public:
        SetMaxSizeˣMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeˣMCommand(const Header&);
        SetMaxSizeˣMCommand(const SetMaxSizeˣMCommand&, const Header&);
        ~SetMaxSizeˣMCommand();

    private:
        Meter   m_x = 0.;
        
        SetMaxSizeˣMCommand(const SetMaxSizeˣMCommand&) = delete;
        SetMaxSizeˣMCommand(SetMaxSizeˣMCommand&&) = delete;
        SetMaxSizeˣMCommand& operator=(const SetMaxSizeˣMCommand&) = delete;
        SetMaxSizeˣMCommand& operator=(SetMaxSizeˣMCommand&&) = delete;
    };
}
