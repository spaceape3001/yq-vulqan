////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetSizeʸ, SpatialCommand)
    public:
        SetSizeʸ(const Header&, double);
    
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʸ(const Header&);
        SetSizeʸ(const SetSizeʸ&, const Header&);
        ~SetSizeʸ();

    private:
        double   m_y = 0.;
        
        SetSizeʸ(const SetSizeʸ&) = delete;
        SetSizeʸ(SetSizeʸ&&) = delete;
        SetSizeʸ& operator=(const SetSizeʸ&) = delete;
        SetSizeʸ& operator=(SetSizeʸ&&) = delete;
    };
}
