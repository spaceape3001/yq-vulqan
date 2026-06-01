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
    class SetSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʷCMCommand, SizeCommand)
    public:
        SetSizeʷCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʷCMCommand(const Header&);
        SetSizeʷCMCommand(const SetSizeʷCMCommand&, const Header&);
        ~SetSizeʷCMCommand();

    private:
        Centimeter   m_w = 0.;
        
        SetSizeʷCMCommand(const SetSizeʷCMCommand&) = delete;
        SetSizeʷCMCommand(SetSizeʷCMCommand&&) = delete;
        SetSizeʷCMCommand& operator=(const SetSizeʷCMCommand&) = delete;
        SetSizeʷCMCommand& operator=(SetSizeʷCMCommand&&) = delete;
    };
}
