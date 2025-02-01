////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddPosition¹, SpatialCommand)
    public:
        AddPosition¹(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddPosition¹();
        AddPosition¹(const AddPosition¹&, const Header&);
        AddPosition¹(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        AddPosition¹(const AddPosition¹&) = delete;
        AddPosition¹(AddPosition¹&&) = delete;
        AddPosition¹& operator=(const AddPosition¹&) = delete;
        AddPosition¹& operator=(AddPosition¹&&) = delete;
    };
}
