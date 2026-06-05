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
    class SetMinSizeʷCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʷCMCommand, SizeCommand)
    public:
        SetMinSizeʷCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʷCMCommand(const Header&);
        SetMinSizeʷCMCommand(const SetMinSizeʷCMCommand&, const Header&);
        ~SetMinSizeʷCMCommand();

    private:
        Centimeter   m_w = 0.;
        
        SetMinSizeʷCMCommand(const SetMinSizeʷCMCommand&) = delete;
        SetMinSizeʷCMCommand(SetMinSizeʷCMCommand&&) = delete;
        SetMinSizeʷCMCommand& operator=(const SetMinSizeʷCMCommand&) = delete;
        SetMinSizeʷCMCommand& operator=(SetMinSizeʷCMCommand&&) = delete;
    };
}
