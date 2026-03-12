////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʸMCommand, SizeCommand)
    public:
        SetSizeʸMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʸMCommand(const Header&);
        SetSizeʸMCommand(const SetSizeʸMCommand&, const Header&);
        ~SetSizeʸMCommand();

    private:
        Meter   m_y = 0.;
        
        SetSizeʸMCommand(const SetSizeʸMCommand&) = delete;
        SetSizeʸMCommand(SetSizeʸMCommand&&) = delete;
        SetSizeʸMCommand& operator=(const SetSizeʸMCommand&) = delete;
        SetSizeʸMCommand& operator=(SetSizeʸMCommand&&) = delete;
    };
}
