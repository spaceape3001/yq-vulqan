////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʷMCommand, SizeCommand)
    public:
        SetSizeʷMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʷMCommand(const Header&);
        SetSizeʷMCommand(const SetSizeʷMCommand&, const Header&);
        ~SetSizeʷMCommand();

    private:
        Meter   m_w = 0.;
        
        SetSizeʷMCommand(const SetSizeʷMCommand&) = delete;
        SetSizeʷMCommand(SetSizeʷMCommand&&) = delete;
        SetSizeʷMCommand& operator=(const SetSizeʷMCommand&) = delete;
        SetSizeʷMCommand& operator=(SetSizeʷMCommand&&) = delete;
    };
}
