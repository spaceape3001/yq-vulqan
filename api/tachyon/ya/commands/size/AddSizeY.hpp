////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class AddSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʸ, SizeCommand)
    public:
        AddSizeʸ(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸ(const AddSizeʸ&, const Header&);
        AddSizeʸ(const Header&);
        ~AddSizeʸ();

    private:
        double  m_Δy = 0.0;
        
        AddSizeʸ(const AddSizeʸ&) = delete;
        AddSizeʸ(AddSizeʸ&&) = delete;
        AddSizeʸ& operator=(const AddSizeʸ&) = delete;
        AddSizeʸ& operator=(AddSizeʸ&&) = delete;
    };
}
