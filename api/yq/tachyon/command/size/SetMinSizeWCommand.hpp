////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʷDCommand, SizeCommand)
    public:
        SetMinSizeʷDCommand(const Header&, double);
    
        static void init_meta();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʷDCommand(const Header&);
        SetMinSizeʷDCommand(const SetMinSizeʷDCommand&, const Header&);
        ~SetMinSizeʷDCommand();

    private:
        double   m_w = 0.;
        
        SetMinSizeʷDCommand(const SetMinSizeʷDCommand&) = delete;
        SetMinSizeʷDCommand(SetMinSizeʷDCommand&&) = delete;
        SetMinSizeʷDCommand& operator=(const SetMinSizeʷDCommand&) = delete;
        SetMinSizeʷDCommand& operator=(SetMinSizeʷDCommand&&) = delete;
    };
}
