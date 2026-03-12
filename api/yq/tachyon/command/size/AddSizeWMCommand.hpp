////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʷMCommand, SizeCommand)
    public:
        AddSizeʷMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʷMCommand(const AddSizeʷMCommand&, const Header&);
        AddSizeʷMCommand(const Header&);
        ~AddSizeʷMCommand();

    private:
        Meter  m_Δw = 0.0;
        
        AddSizeʷMCommand(const AddSizeʷMCommand&) = delete;
        AddSizeʷMCommand(AddSizeʷMCommand&&) = delete;
        AddSizeʷMCommand& operator=(const AddSizeʷMCommand&) = delete;
        AddSizeʷMCommand& operator=(AddSizeʷMCommand&&) = delete;
    };
}
