////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʸDCommand, SizeCommand)
    public:
        SetSizeʸDCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʸDCommand(const Header&);
        SetSizeʸDCommand(const SetSizeʸDCommand&, const Header&);
        ~SetSizeʸDCommand();

    private:
        double   m_y = 0.;
        
        SetSizeʸDCommand(const SetSizeʸDCommand&) = delete;
        SetSizeʸDCommand(SetSizeʸDCommand&&) = delete;
        SetSizeʸDCommand& operator=(const SetSizeʸDCommand&) = delete;
        SetSizeʸDCommand& operator=(SetSizeʸDCommand&&) = delete;
    };
}
