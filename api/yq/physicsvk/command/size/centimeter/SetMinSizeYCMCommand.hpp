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
    class SetMinSizeʸCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʸCMCommand, SizeCommand)
    public:
        SetMinSizeʸCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʸCMCommand(const Header&);
        SetMinSizeʸCMCommand(const SetMinSizeʸCMCommand&, const Header&);
        ~SetMinSizeʸCMCommand();

    private:
        Centimeter   m_y = 0.;
        
        SetMinSizeʸCMCommand(const SetMinSizeʸCMCommand&) = delete;
        SetMinSizeʸCMCommand(SetMinSizeʸCMCommand&&) = delete;
        SetMinSizeʸCMCommand& operator=(const SetMinSizeʸCMCommand&) = delete;
        SetMinSizeʸCMCommand& operator=(SetMinSizeʸCMCommand&&) = delete;
    };
}
