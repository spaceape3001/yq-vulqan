////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddMinSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʸMCommand, SizeCommand)
    public:
        AddMinSizeʸMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʸMCommand(const AddMinSizeʸMCommand&, const Header&);
        AddMinSizeʸMCommand(const Header&);
        ~AddMinSizeʸMCommand();

    private:
        Meter  m_Δy = 0.0;
        
        AddMinSizeʸMCommand(const AddMinSizeʸMCommand&) = delete;
        AddMinSizeʸMCommand(AddMinSizeʸMCommand&&) = delete;
        AddMinSizeʸMCommand& operator=(const AddMinSizeʸMCommand&) = delete;
        AddMinSizeʸMCommand& operator=(AddMinSizeʸMCommand&&) = delete;
    };
}
