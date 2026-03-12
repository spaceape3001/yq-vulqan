////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddMinSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʸDCommand, SizeCommand)
    public:
        AddMinSizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʸDCommand(const AddMinSizeʸDCommand&, const Header&);
        AddMinSizeʸDCommand(const Header&);
        ~AddMinSizeʸDCommand();

    private:
        double  m_Δy = 0.0;
        
        AddMinSizeʸDCommand(const AddMinSizeʸDCommand&) = delete;
        AddMinSizeʸDCommand(AddMinSizeʸDCommand&&) = delete;
        AddMinSizeʸDCommand& operator=(const AddMinSizeʸDCommand&) = delete;
        AddMinSizeʸDCommand& operator=(AddMinSizeʸDCommand&&) = delete;
    };
}
