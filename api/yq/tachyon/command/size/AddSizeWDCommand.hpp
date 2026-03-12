////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʷDCommand, SizeCommand)
    public:
        AddSizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʷDCommand(const AddSizeʷDCommand&, const Header&);
        AddSizeʷDCommand(const Header&);
        ~AddSizeʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        AddSizeʷDCommand(const AddSizeʷDCommand&) = delete;
        AddSizeʷDCommand(AddSizeʷDCommand&&) = delete;
        AddSizeʷDCommand& operator=(const AddSizeʷDCommand&) = delete;
        AddSizeʷDCommand& operator=(AddSizeʷDCommand&&) = delete;
    };
}
