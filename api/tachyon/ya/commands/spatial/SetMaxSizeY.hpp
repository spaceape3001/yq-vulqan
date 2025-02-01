////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʸ, SpatialCommand)
    public:
        SetMaxSizeʸ(const Header&, double);
    
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʸ(const Header&);
        SetMaxSizeʸ(const SetMaxSizeʸ&, const Header&);
        ~SetMaxSizeʸ();

    private:
        double   m_y = 0.;
        
        SetMaxSizeʸ(const SetMaxSizeʸ&) = delete;
        SetMaxSizeʸ(SetMaxSizeʸ&&) = delete;
        SetMaxSizeʸ& operator=(const SetMaxSizeʸ&) = delete;
        SetMaxSizeʸ& operator=(SetMaxSizeʸ&&) = delete;
    };
}
