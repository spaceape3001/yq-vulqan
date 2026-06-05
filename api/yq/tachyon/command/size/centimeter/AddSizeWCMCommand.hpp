////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʷCMCommand, SizeCommand)
    public:
        AddSizeʷCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʷCMCommand(const AddSizeʷCMCommand&, const Header&);
        AddSizeʷCMCommand(const Header&);
        ~AddSizeʷCMCommand();

    private:
        Centimeter  m_Δw = 0.0;
        
        AddSizeʷCMCommand(const AddSizeʷCMCommand&) = delete;
        AddSizeʷCMCommand(AddSizeʷCMCommand&&) = delete;
        AddSizeʷCMCommand& operator=(const AddSizeʷCMCommand&) = delete;
        AddSizeʷCMCommand& operator=(AddSizeʷCMCommand&&) = delete;
    };
}
