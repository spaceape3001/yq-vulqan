////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʸMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʸMCommand, SizeCommand)
    public:
        SetMinSizeʸMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʸMCommand(const Header&);
        SetMinSizeʸMCommand(const SetMinSizeʸMCommand&, const Header&);
        ~SetMinSizeʸMCommand();

    private:
        Meter   m_y = 0.;
        
        SetMinSizeʸMCommand(const SetMinSizeʸMCommand&) = delete;
        SetMinSizeʸMCommand(SetMinSizeʸMCommand&&) = delete;
        SetMinSizeʸMCommand& operator=(const SetMinSizeʸMCommand&) = delete;
        SetMinSizeʸMCommand& operator=(SetMinSizeʸMCommand&&) = delete;
    };
}
