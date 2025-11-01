////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddMaxSizeʸCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʸCommand, SizeCommand)
    public:
        AddMaxSizeʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʸCommand(const AddMaxSizeʸCommand&, const Header&);
        AddMaxSizeʸCommand(const Header&);
        ~AddMaxSizeʸCommand();

    private:
        double  m_Δy = 0.0;
        
        AddMaxSizeʸCommand(const AddMaxSizeʸCommand&) = delete;
        AddMaxSizeʸCommand(AddMaxSizeʸCommand&&) = delete;
        AddMaxSizeʸCommand& operator=(const AddMaxSizeʸCommand&) = delete;
        AddMaxSizeʸCommand& operator=(AddMaxSizeʸCommand&&) = delete;
    };
}
