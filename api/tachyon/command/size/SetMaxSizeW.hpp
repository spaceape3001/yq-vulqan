////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSizeʷ, SizeCommand)
    public:
        SetMaxSizeʷ(const Header&, double);
    
        static void init_info();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSizeʷ(const Header&);
        SetMaxSizeʷ(const SetMaxSizeʷ&, const Header&);
        ~SetMaxSizeʷ();

    private:
        double   m_w = 0.;
        
        SetMaxSizeʷ(const SetMaxSizeʷ&) = delete;
        SetMaxSizeʷ(SetMaxSizeʷ&&) = delete;
        SetMaxSizeʷ& operator=(const SetMaxSizeʷ&) = delete;
        SetMaxSizeʷ& operator=(SetMaxSizeʷ&&) = delete;
    };
}
