////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʸCommand, SizeCommand)
    public:
        SetMinSizeʸCommand(const Header&, double);
    
        static void init_meta();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʸCommand(const Header&);
        SetMinSizeʸCommand(const SetMinSizeʸCommand&, const Header&);
        ~SetMinSizeʸCommand();

    private:
        double   m_y = 0.;
        
        SetMinSizeʸCommand(const SetMinSizeʸCommand&) = delete;
        SetMinSizeʸCommand(SetMinSizeʸCommand&&) = delete;
        SetMinSizeʸCommand& operator=(const SetMinSizeʸCommand&) = delete;
        SetMinSizeʸCommand& operator=(SetMinSizeʸCommand&&) = delete;
    };
}
