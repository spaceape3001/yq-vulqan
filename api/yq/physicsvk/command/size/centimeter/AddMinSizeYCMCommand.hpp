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

    //! Instructs an object to set it's y-position
    class AddMinSizeʸCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʸCMCommand, SizeCommand)
    public:
        AddMinSizeʸCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʸCMCommand(const AddMinSizeʸCMCommand&, const Header&);
        AddMinSizeʸCMCommand(const Header&);
        ~AddMinSizeʸCMCommand();

    private:
        Centimeter  m_Δy = 0.0;
        
        AddMinSizeʸCMCommand(const AddMinSizeʸCMCommand&) = delete;
        AddMinSizeʸCMCommand(AddMinSizeʸCMCommand&&) = delete;
        AddMinSizeʸCMCommand& operator=(const AddMinSizeʸCMCommand&) = delete;
        AddMinSizeʸCMCommand& operator=(AddMinSizeʸCMCommand&&) = delete;
    };
}
