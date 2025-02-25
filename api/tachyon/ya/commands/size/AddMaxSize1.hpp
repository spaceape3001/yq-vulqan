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
    class AddMaxSize¹ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize¹, SizeCommand)
    public:
        AddMaxSize¹(const Header&, const Vector1D&);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddMaxSize¹();
        AddMaxSize¹(const AddMaxSize¹&, const Header&);
        AddMaxSize¹(const Header&);

    private:
        Vector1D  m_Δ = ZERO;
        
        AddMaxSize¹(const AddMaxSize¹&) = delete;
        AddMaxSize¹(AddMaxSize¹&&) = delete;
        AddMaxSize¹& operator=(const AddMaxSize¹&) = delete;
        AddMaxSize¹& operator=(AddMaxSize¹&&) = delete;
    };
}
