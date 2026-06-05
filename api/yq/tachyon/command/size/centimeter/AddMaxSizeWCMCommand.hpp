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
    class AddMaxSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʷCMCommand, SizeCommand)
    public:
        AddMaxSizeʷCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʷCMCommand(const AddMaxSizeʷCMCommand&, const Header&);
        AddMaxSizeʷCMCommand(const Header&);
        ~AddMaxSizeʷCMCommand();

    private:
        Centimeter  m_Δw = 0.0;
        
        AddMaxSizeʷCMCommand(const AddMaxSizeʷCMCommand&) = delete;
        AddMaxSizeʷCMCommand(AddMaxSizeʷCMCommand&&) = delete;
        AddMaxSizeʷCMCommand& operator=(const AddMaxSizeʷCMCommand&) = delete;
        AddMaxSizeʷCMCommand& operator=(AddMaxSizeʷCMCommand&&) = delete;
    };
}
