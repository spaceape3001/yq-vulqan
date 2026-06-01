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
    class SetMaxSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʷCMCommand, SizeCommand)
    public:
        SetMaxSizeʷCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʷCMCommand(const Header&);
        SetMaxSizeʷCMCommand(const SetMaxSizeʷCMCommand&, const Header&);
        ~SetMaxSizeʷCMCommand();

    private:
        Centimeter   m_w = 0.;
        
        SetMaxSizeʷCMCommand(const SetMaxSizeʷCMCommand&) = delete;
        SetMaxSizeʷCMCommand(SetMaxSizeʷCMCommand&&) = delete;
        SetMaxSizeʷCMCommand& operator=(const SetMaxSizeʷCMCommand&) = delete;
        SetMaxSizeʷCMCommand& operator=(SetMaxSizeʷCMCommand&&) = delete;
    };
}
