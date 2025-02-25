////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize¹ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize¹, SizeCommand)
    public:
        AddSize¹(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddSize¹();
        AddSize¹(const AddSize¹&, const Header&);
        AddSize¹(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddSize¹(const AddSize¹&) = delete;
        AddSize¹(AddSize¹&&) = delete;
        AddSize¹& operator=(const AddSize¹&) = delete;
        AddSize¹& operator=(AddSize¹&&) = delete;
    };
}
