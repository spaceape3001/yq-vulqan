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
    class AddMaxSizeʸDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʸDCommand, SizeCommand)
    public:
        AddMaxSizeʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʸDCommand(const AddMaxSizeʸDCommand&, const Header&);
        AddMaxSizeʸDCommand(const Header&);
        ~AddMaxSizeʸDCommand();

    private:
        double  m_Δy = 0.0;
        
        AddMaxSizeʸDCommand(const AddMaxSizeʸDCommand&) = delete;
        AddMaxSizeʸDCommand(AddMaxSizeʸDCommand&&) = delete;
        AddMaxSizeʸDCommand& operator=(const AddMaxSizeʸDCommand&) = delete;
        AddMaxSizeʸDCommand& operator=(AddMaxSizeʸDCommand&&) = delete;
    };
}
