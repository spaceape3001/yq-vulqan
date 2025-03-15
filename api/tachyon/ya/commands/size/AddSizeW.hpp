////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeʷ, SizeCommand)
    public:
        AddSizeʷ(const Header&, double);
        
        static void init_info();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeʷ(const AddSizeʷ&, const Header&);
        AddSizeʷ(const Header&);
        ~AddSizeʷ();

    private:
        double  m_Δw = 0.0;
        
        AddSizeʷ(const AddSizeʷ&) = delete;
        AddSizeʷ(AddSizeʷ&&) = delete;
        AddSizeʷ& operator=(const AddSizeʷ&) = delete;
        AddSizeʷ& operator=(AddSizeʷ&&) = delete;
    };
}
