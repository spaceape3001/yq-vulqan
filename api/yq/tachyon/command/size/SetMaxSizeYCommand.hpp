////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʸCommand, SizeCommand)
    public:
        SetMaxSizeʸCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʸCommand(const Header&);
        SetMaxSizeʸCommand(const SetMaxSizeʸCommand&, const Header&);
        ~SetMaxSizeʸCommand();

    private:
        double   m_y = 0.;
        
        SetMaxSizeʸCommand(const SetMaxSizeʸCommand&) = delete;
        SetMaxSizeʸCommand(SetMaxSizeʸCommand&&) = delete;
        SetMaxSizeʸCommand& operator=(const SetMaxSizeʸCommand&) = delete;
        SetMaxSizeʸCommand& operator=(SetMaxSizeʸCommand&&) = delete;
    };
}
