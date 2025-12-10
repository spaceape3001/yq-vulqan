////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʸCommand, SizeCommand)
    public:
        SetSizeʸCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʸCommand(const Header&);
        SetSizeʸCommand(const SetSizeʸCommand&, const Header&);
        ~SetSizeʸCommand();

    private:
        double   m_y = 0.;
        
        SetSizeʸCommand(const SetSizeʸCommand&) = delete;
        SetSizeʸCommand(SetSizeʸCommand&&) = delete;
        SetSizeʸCommand& operator=(const SetSizeʸCommand&) = delete;
        SetSizeʸCommand& operator=(SetSizeʸCommand&&) = delete;
    };
}
