////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʷMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʷMCommand, SizeCommand)
    public:
        SetMinSizeʷMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʷMCommand(const Header&);
        SetMinSizeʷMCommand(const SetMinSizeʷMCommand&, const Header&);
        ~SetMinSizeʷMCommand();

    private:
        Meter   m_w = 0.;
        
        SetMinSizeʷMCommand(const SetMinSizeʷMCommand&) = delete;
        SetMinSizeʷMCommand(SetMinSizeʷMCommand&&) = delete;
        SetMinSizeʷMCommand& operator=(const SetMinSizeʷMCommand&) = delete;
        SetMinSizeʷMCommand& operator=(SetMinSizeʷMCommand&&) = delete;
    };
}
