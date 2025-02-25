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
    class AddMaxSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʸ, SizeCommand)
    public:
        AddMaxSizeʸ(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʸ(const AddMaxSizeʸ&, const Header&);
        AddMaxSizeʸ(const Header&);
        ~AddMaxSizeʸ();

    private:
        double  m_Δy = 0.0;
        
        AddMaxSizeʸ(const AddMaxSizeʸ&) = delete;
        AddMaxSizeʸ(AddMaxSizeʸ&&) = delete;
        AddMaxSizeʸ& operator=(const AddMaxSizeʸ&) = delete;
        AddMaxSizeʸ& operator=(AddMaxSizeʸ&&) = delete;
    };
}
