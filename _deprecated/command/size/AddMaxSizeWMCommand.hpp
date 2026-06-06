////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMaxSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʷMCommand, SizeCommand)
    public:
        AddMaxSizeʷMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʷMCommand(const AddMaxSizeʷMCommand&, const Header&);
        AddMaxSizeʷMCommand(const Header&);
        ~AddMaxSizeʷMCommand();

    private:
        Meter  m_Δw = 0.0;
        
        AddMaxSizeʷMCommand(const AddMaxSizeʷMCommand&) = delete;
        AddMaxSizeʷMCommand(AddMaxSizeʷMCommand&&) = delete;
        AddMaxSizeʷMCommand& operator=(const AddMaxSizeʷMCommand&) = delete;
        AddMaxSizeʷMCommand& operator=(AddMaxSizeʷMCommand&&) = delete;
    };
}
