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
    class AddMinSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʸ, SizeCommand)
    public:
        AddMinSizeʸ(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʸ(const AddMinSizeʸ&, const Header&);
        AddMinSizeʸ(const Header&);
        ~AddMinSizeʸ();

    private:
        double  m_Δy = 0.0;
        
        AddMinSizeʸ(const AddMinSizeʸ&) = delete;
        AddMinSizeʸ(AddMinSizeʸ&&) = delete;
        AddMinSizeʸ& operator=(const AddMinSizeʸ&) = delete;
        AddMinSizeʸ& operator=(AddMinSizeʸ&&) = delete;
    };
}
