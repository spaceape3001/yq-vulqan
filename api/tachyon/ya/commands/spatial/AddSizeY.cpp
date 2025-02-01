////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class AddSizeʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSizeʸ, SpatialCommand)
    public:
        AddSizeʸ(const Header&, double);
    
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʸ(const Header&);
        AddSizeʸ(const AddSizeʸ&, const Header&);
        ~AddSizeʸ();

    private:
        double   m_y = 0.;
        
        AddSizeʸ(const AddSizeʸ&) = delete;
        AddSizeʸ(AddSizeʸ&&) = delete;
        AddSizeʸ& operator=(const AddSizeʸ&) = delete;
        AddSizeʸ& operator=(AddSizeʸ&&) = delete;
    };
}
