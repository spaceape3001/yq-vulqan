////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeʷ, SizeCommand)
    public:
        AddMinSizeʷ(const Header&, double);
        
        static void init_info();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeʷ(const AddMinSizeʷ&, const Header&);
        AddMinSizeʷ(const Header&);
        ~AddMinSizeʷ();

    private:
        double  m_Δw = 0.0;
        
        AddMinSizeʷ(const AddMinSizeʷ&) = delete;
        AddMinSizeʷ(AddMinSizeʷ&&) = delete;
        AddMinSizeʷ& operator=(const AddMinSizeʷ&) = delete;
        AddMinSizeʷ& operator=(AddMinSizeʷ&&) = delete;
    };
}
