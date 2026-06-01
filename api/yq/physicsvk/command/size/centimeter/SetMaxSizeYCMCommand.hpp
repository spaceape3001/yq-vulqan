////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʸCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʸCMCommand, SizeCommand)
    public:
        SetMaxSizeʸCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʸCMCommand(const Header&);
        SetMaxSizeʸCMCommand(const SetMaxSizeʸCMCommand&, const Header&);
        ~SetMaxSizeʸCMCommand();

    private:
        Centimeter   m_y = 0.;
        
        SetMaxSizeʸCMCommand(const SetMaxSizeʸCMCommand&) = delete;
        SetMaxSizeʸCMCommand(SetMaxSizeʸCMCommand&&) = delete;
        SetMaxSizeʸCMCommand& operator=(const SetMaxSizeʸCMCommand&) = delete;
        SetMaxSizeʸCMCommand& operator=(SetMaxSizeʸCMCommand&&) = delete;
    };
}
