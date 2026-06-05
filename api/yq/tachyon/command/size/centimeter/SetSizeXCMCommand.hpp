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
    class SetSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeˣCMCommand, SizeCommand)
    public:
        SetSizeˣCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeˣCMCommand(const Header&);
        SetSizeˣCMCommand(const SetSizeˣCMCommand&, const Header&);
        ~SetSizeˣCMCommand();

    private:
        Centimeter   m_x = 0.;
        
        SetSizeˣCMCommand(const SetSizeˣCMCommand&) = delete;
        SetSizeˣCMCommand(SetSizeˣCMCommand&&) = delete;
        SetSizeˣCMCommand& operator=(const SetSizeˣCMCommand&) = delete;
        SetSizeˣCMCommand& operator=(SetSizeˣCMCommand&&) = delete;
    };
}
