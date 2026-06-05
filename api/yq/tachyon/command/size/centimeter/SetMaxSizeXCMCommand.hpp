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
    class SetMaxSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeˣCMCommand, SizeCommand)
    public:
        SetMaxSizeˣCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeˣCMCommand(const Header&);
        SetMaxSizeˣCMCommand(const SetMaxSizeˣCMCommand&, const Header&);
        ~SetMaxSizeˣCMCommand();

    private:
        Centimeter   m_x = 0.;
        
        SetMaxSizeˣCMCommand(const SetMaxSizeˣCMCommand&) = delete;
        SetMaxSizeˣCMCommand(SetMaxSizeˣCMCommand&&) = delete;
        SetMaxSizeˣCMCommand& operator=(const SetMaxSizeˣCMCommand&) = delete;
        SetMaxSizeˣCMCommand& operator=(SetMaxSizeˣCMCommand&&) = delete;
    };
}
