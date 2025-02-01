////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʸ, SpatialCommand)
    public:
        SetMinSizeʸ(const Header&, double);
    
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʸ(const Header&);
        SetMinSizeʸ(const SetMinSizeʸ&, const Header&);
        ~SetMinSizeʸ();

    private:
        double   m_y = 0.;
        
        SetMinSizeʸ(const SetMinSizeʸ&) = delete;
        SetMinSizeʸ(SetMinSizeʸ&&) = delete;
        SetMinSizeʸ& operator=(const SetMinSizeʸ&) = delete;
        SetMinSizeʸ& operator=(SetMinSizeʸ&&) = delete;
    };
}
