////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʷCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʷCommand, SizeCommand)
    public:
        SetMaxSizeʷCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʷCommand(const Header&);
        SetMaxSizeʷCommand(const SetMaxSizeʷCommand&, const Header&);
        ~SetMaxSizeʷCommand();

    private:
        double   m_w = 0.;
        
        SetMaxSizeʷCommand(const SetMaxSizeʷCommand&) = delete;
        SetMaxSizeʷCommand(SetMaxSizeʷCommand&&) = delete;
        SetMaxSizeʷCommand& operator=(const SetMaxSizeʷCommand&) = delete;
        SetMaxSizeʷCommand& operator=(SetMaxSizeʷCommand&&) = delete;
    };
}
