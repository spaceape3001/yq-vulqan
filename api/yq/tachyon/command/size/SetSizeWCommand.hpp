////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʷDCommand, SizeCommand)
    public:
        SetSizeʷDCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʷDCommand(const Header&);
        SetSizeʷDCommand(const SetSizeʷDCommand&, const Header&);
        ~SetSizeʷDCommand();

    private:
        double   m_w = 0.;
        
        SetSizeʷDCommand(const SetSizeʷDCommand&) = delete;
        SetSizeʷDCommand(SetSizeʷDCommand&&) = delete;
        SetSizeʷDCommand& operator=(const SetSizeʷDCommand&) = delete;
        SetSizeʷDCommand& operator=(SetSizeʷDCommand&&) = delete;
    };
}
