////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʸMCommand, SizeCommand)
    public:
        SetMaxSizeʸMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʸMCommand(const Header&);
        SetMaxSizeʸMCommand(const SetMaxSizeʸMCommand&, const Header&);
        ~SetMaxSizeʸMCommand();

    private:
        Meter   m_y = 0.;
        
        SetMaxSizeʸMCommand(const SetMaxSizeʸMCommand&) = delete;
        SetMaxSizeʸMCommand(SetMaxSizeʸMCommand&&) = delete;
        SetMaxSizeʸMCommand& operator=(const SetMaxSizeʸMCommand&) = delete;
        SetMaxSizeʸMCommand& operator=(SetMaxSizeʸMCommand&&) = delete;
    };
}
