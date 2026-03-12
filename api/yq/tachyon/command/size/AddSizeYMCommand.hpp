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
    class AddSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʸMCommand, SizeCommand)
    public:
        AddSizeʸMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸMCommand(const AddSizeʸMCommand&, const Header&);
        AddSizeʸMCommand(const Header&);
        ~AddSizeʸMCommand();

    private:
        Meter  m_Δy = 0.0;
        
        AddSizeʸMCommand(const AddSizeʸMCommand&) = delete;
        AddSizeʸMCommand(AddSizeʸMCommand&&) = delete;
        AddSizeʸMCommand& operator=(const AddSizeʸMCommand&) = delete;
        AddSizeʸMCommand& operator=(AddSizeʸMCommand&&) = delete;
    };
}
