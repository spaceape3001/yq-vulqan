////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʸ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʸ, SizeCommand)
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
