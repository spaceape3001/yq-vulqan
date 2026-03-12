////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʷDCommand, SizeCommand)
    public:
        SetMaxSizeʷDCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʷDCommand(const Header&);
        SetMaxSizeʷDCommand(const SetMaxSizeʷDCommand&, const Header&);
        ~SetMaxSizeʷDCommand();

    private:
        double   m_w = 0.;
        
        SetMaxSizeʷDCommand(const SetMaxSizeʷDCommand&) = delete;
        SetMaxSizeʷDCommand(SetMaxSizeʷDCommand&&) = delete;
        SetMaxSizeʷDCommand& operator=(const SetMaxSizeʷDCommand&) = delete;
        SetMaxSizeʷDCommand& operator=(SetMaxSizeʷDCommand&&) = delete;
    };
}
