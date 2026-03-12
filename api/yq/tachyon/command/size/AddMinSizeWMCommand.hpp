////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeʷDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʷDCommand, SizeCommand)
    public:
        AddMinSizeʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʷDCommand(const AddMinSizeʷDCommand&, const Header&);
        AddMinSizeʷDCommand(const Header&);
        ~AddMinSizeʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        AddMinSizeʷDCommand(const AddMinSizeʷDCommand&) = delete;
        AddMinSizeʷDCommand(AddMinSizeʷDCommand&&) = delete;
        AddMinSizeʷDCommand& operator=(const AddMinSizeʷDCommand&) = delete;
        AddMinSizeʷDCommand& operator=(AddMinSizeʷDCommand&&) = delete;
    };
}
