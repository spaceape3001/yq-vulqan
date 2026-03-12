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
    class AddMaxSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʸMCommand, SizeCommand)
    public:
        AddMaxSizeʸMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʸMCommand(const AddMaxSizeʸMCommand&, const Header&);
        AddMaxSizeʸMCommand(const Header&);
        ~AddMaxSizeʸMCommand();

    private:
        Meter  m_Δy = 0.0;
        
        AddMaxSizeʸMCommand(const AddMaxSizeʸMCommand&) = delete;
        AddMaxSizeʸMCommand(AddMaxSizeʸMCommand&&) = delete;
        AddMaxSizeʸMCommand& operator=(const AddMaxSizeʸMCommand&) = delete;
        AddMaxSizeʸMCommand& operator=(AddMaxSizeʸMCommand&&) = delete;
    };
}
