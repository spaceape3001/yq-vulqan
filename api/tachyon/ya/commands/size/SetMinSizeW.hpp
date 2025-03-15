////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeʷ, SizeCommand)
    public:
        SetMinSizeʷ(const Header&, double);
    
        static void init_info();
        
        double  w() const { return m_w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeʷ(const Header&);
        SetMinSizeʷ(const SetMinSizeʷ&, const Header&);
        ~SetMinSizeʷ();

    private:
        double   m_w = 0.;
        
        SetMinSizeʷ(const SetMinSizeʷ&) = delete;
        SetMinSizeʷ(SetMinSizeʷ&&) = delete;
        SetMinSizeʷ& operator=(const SetMinSizeʷ&) = delete;
        SetMinSizeʷ& operator=(SetMinSizeʷ&&) = delete;
    };
}
