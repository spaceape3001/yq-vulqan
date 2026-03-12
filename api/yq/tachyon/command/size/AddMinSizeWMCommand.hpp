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

    //! Instructs an object to set it's x-scale
    class AddMinSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʷMCommand, SizeCommand)
    public:
        AddMinSizeʷMCommand(const Header&, Meter);
        
        static void init_meta();
        
        Meter  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʷMCommand(const AddMinSizeʷMCommand&, const Header&);
        AddMinSizeʷMCommand(const Header&);
        ~AddMinSizeʷMCommand();

    private:
        Meter  m_Δw = 0.0;
        
        AddMinSizeʷMCommand(const AddMinSizeʷMCommand&) = delete;
        AddMinSizeʷMCommand(AddMinSizeʷMCommand&&) = delete;
        AddMinSizeʷMCommand& operator=(const AddMinSizeʷMCommand&) = delete;
        AddMinSizeʷMCommand& operator=(AddMinSizeʷMCommand&&) = delete;
    };
}
