////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSizeʷ, SizeCommand)
    public:
        SetSizeʷ(const Header&, double);
    
        static void init_info();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSizeʷ(const Header&);
        SetSizeʷ(const SetSizeʷ&, const Header&);
        ~SetSizeʷ();

    private:
        double   m_w = 0.;
        
        SetSizeʷ(const SetSizeʷ&) = delete;
        SetSizeʷ(SetSizeʷ&&) = delete;
        SetSizeʷ& operator=(const SetSizeʷ&) = delete;
        SetSizeʷ& operator=(SetSizeʷ&&) = delete;
    };
}
