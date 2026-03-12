////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʸDCommand, SizeCommand)
    public:
        SetMaxSizeʸDCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʸDCommand(const Header&);
        SetMaxSizeʸDCommand(const SetMaxSizeʸDCommand&, const Header&);
        ~SetMaxSizeʸDCommand();

    private:
        double   m_y = 0.;
        
        SetMaxSizeʸDCommand(const SetMaxSizeʸDCommand&) = delete;
        SetMaxSizeʸDCommand(SetMaxSizeʸDCommand&&) = delete;
        SetMaxSizeʸDCommand& operator=(const SetMaxSizeʸDCommand&) = delete;
        SetMaxSizeʸDCommand& operator=(SetMaxSizeʸDCommand&&) = delete;
    };
}
