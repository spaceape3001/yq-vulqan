////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʷCMCommand, SizeCommand)
    public:
        AddMinSizeʷCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʷCMCommand(const AddMinSizeʷCMCommand&, const Header&);
        AddMinSizeʷCMCommand(const Header&);
        ~AddMinSizeʷCMCommand();

    private:
        Centimeter  m_Δw = 0.0;
        
        AddMinSizeʷCMCommand(const AddMinSizeʷCMCommand&) = delete;
        AddMinSizeʷCMCommand(AddMinSizeʷCMCommand&&) = delete;
        AddMinSizeʷCMCommand& operator=(const AddMinSizeʷCMCommand&) = delete;
        AddMinSizeʷCMCommand& operator=(AddMinSizeʷCMCommand&&) = delete;
    };
}
