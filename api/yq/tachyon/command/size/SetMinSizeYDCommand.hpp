////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʸDCommand, SizeCommand)
    public:
        SetMinSizeʸDCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʸDCommand(const Header&);
        SetMinSizeʸDCommand(const SetMinSizeʸDCommand&, const Header&);
        ~SetMinSizeʸDCommand();

    private:
        double   m_y = 0.;
        
        SetMinSizeʸDCommand(const SetMinSizeʸDCommand&) = delete;
        SetMinSizeʸDCommand(SetMinSizeʸDCommand&&) = delete;
        SetMinSizeʸDCommand& operator=(const SetMinSizeʸDCommand&) = delete;
        SetMinSizeʸDCommand& operator=(SetMinSizeʸDCommand&&) = delete;
    };
}
