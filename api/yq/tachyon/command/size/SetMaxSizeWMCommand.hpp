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
    class SetMaxSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʷMCommand, SizeCommand)
    public:
        SetMaxSizeʷMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʷMCommand(const Header&);
        SetMaxSizeʷMCommand(const SetMaxSizeʷMCommand&, const Header&);
        ~SetMaxSizeʷMCommand();

    private:
        Meter   m_w = 0.;
        
        SetMaxSizeʷMCommand(const SetMaxSizeʷMCommand&) = delete;
        SetMaxSizeʷMCommand(SetMaxSizeʷMCommand&&) = delete;
        SetMaxSizeʷMCommand& operator=(const SetMaxSizeʷMCommand&) = delete;
        SetMaxSizeʷMCommand& operator=(SetMaxSizeʷMCommand&&) = delete;
    };
}
