////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʸCommand, SizeCommand)
    public:
        AddSizeʸCommand(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸCommand(const AddSizeʸCommand&, const Header&);
        AddSizeʸCommand(const Header&);
        ~AddSizeʸCommand();

    private:
        double  m_Δy = 0.0;
        
        AddSizeʸCommand(const AddSizeʸCommand&) = delete;
        AddSizeʸCommand(AddSizeʸCommand&&) = delete;
        AddSizeʸCommand& operator=(const AddSizeʸCommand&) = delete;
        AddSizeʸCommand& operator=(AddSizeʸCommand&&) = delete;
    };
}
