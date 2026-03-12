////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʸDCommand, SizeCommand)
    public:
        AddSizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸDCommand(const AddSizeʸDCommand&, const Header&);
        AddSizeʸDCommand(const Header&);
        ~AddSizeʸDCommand();

    private:
        double  m_Δy = 0.0;
        
        AddSizeʸDCommand(const AddSizeʸDCommand&) = delete;
        AddSizeʸDCommand(AddSizeʸDCommand&&) = delete;
        AddSizeʸDCommand& operator=(const AddSizeʸDCommand&) = delete;
        AddSizeʸDCommand& operator=(AddSizeʸDCommand&&) = delete;
    };
}
