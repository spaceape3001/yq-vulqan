////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʷCommand, SizeCommand)
    public:
        SetSizeʷCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʷCommand(const Header&);
        SetSizeʷCommand(const SetSizeʷCommand&, const Header&);
        ~SetSizeʷCommand();

    private:
        double   m_w = 0.;
        
        SetSizeʷCommand(const SetSizeʷCommand&) = delete;
        SetSizeʷCommand(SetSizeʷCommand&&) = delete;
        SetSizeʷCommand& operator=(const SetSizeʷCommand&) = delete;
        SetSizeʷCommand& operator=(SetSizeʷCommand&&) = delete;
    };
}
