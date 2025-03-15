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
    class AddMaxSizeʷ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeʷ, SizeCommand)
    public:
        AddMaxSizeʷ(const Header&, double);
        
        static void init_info();
        
        double  Δw() const { return m_Δw; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeʷ(const AddMaxSizeʷ&, const Header&);
        AddMaxSizeʷ(const Header&);
        ~AddMaxSizeʷ();

    private:
        double  m_Δw = 0.0;
        
        AddMaxSizeʷ(const AddMaxSizeʷ&) = delete;
        AddMaxSizeʷ(AddMaxSizeʷ&&) = delete;
        AddMaxSizeʷ& operator=(const AddMaxSizeʷ&) = delete;
        AddMaxSizeʷ& operator=(AddMaxSizeʷ&&) = delete;
    };
}
