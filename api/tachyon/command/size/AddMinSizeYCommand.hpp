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
    class AddMinSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʸCommand, SizeCommand)
    public:
        AddMinSizeʸCommand(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʸCommand(const AddMinSizeʸCommand&, const Header&);
        AddMinSizeʸCommand(const Header&);
        ~AddMinSizeʸCommand();

    private:
        double  m_Δy = 0.0;
        
        AddMinSizeʸCommand(const AddMinSizeʸCommand&) = delete;
        AddMinSizeʸCommand(AddMinSizeʸCommand&&) = delete;
        AddMinSizeʸCommand& operator=(const AddMinSizeʸCommand&) = delete;
        AddMinSizeʸCommand& operator=(AddMinSizeʸCommand&&) = delete;
    };
}
