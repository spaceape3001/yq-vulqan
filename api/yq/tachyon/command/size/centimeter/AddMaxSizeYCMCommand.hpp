////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddMaxSizeʸCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʸCMCommand, SizeCommand)
    public:
        AddMaxSizeʸCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʸCMCommand(const AddMaxSizeʸCMCommand&, const Header&);
        AddMaxSizeʸCMCommand(const Header&);
        ~AddMaxSizeʸCMCommand();

    private:
        Centimeter  m_Δy = 0.0;
        
        AddMaxSizeʸCMCommand(const AddMaxSizeʸCMCommand&) = delete;
        AddMaxSizeʸCMCommand(AddMaxSizeʸCMCommand&&) = delete;
        AddMaxSizeʸCMCommand& operator=(const AddMaxSizeʸCMCommand&) = delete;
        AddMaxSizeʸCMCommand& operator=(AddMaxSizeʸCMCommand&&) = delete;
    };
}
