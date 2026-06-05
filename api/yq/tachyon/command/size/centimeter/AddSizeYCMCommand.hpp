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
    class AddSizeʸCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʸCMCommand, SizeCommand)
    public:
        AddSizeʸCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸCMCommand(const AddSizeʸCMCommand&, const Header&);
        AddSizeʸCMCommand(const Header&);
        ~AddSizeʸCMCommand();

    private:
        Centimeter  m_Δy = 0.0;
        
        AddSizeʸCMCommand(const AddSizeʸCMCommand&) = delete;
        AddSizeʸCMCommand(AddSizeʸCMCommand&&) = delete;
        AddSizeʸCMCommand& operator=(const AddSizeʸCMCommand&) = delete;
        AddSizeʸCMCommand& operator=(AddSizeʸCMCommand&&) = delete;
    };
}
