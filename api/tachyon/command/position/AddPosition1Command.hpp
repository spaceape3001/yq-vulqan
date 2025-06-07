////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition¹Command : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition¹Command, PositionCommand)
    public:
        AddPosition¹Command(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddPosition¹Command();
        AddPosition¹Command(const AddPosition¹Command&, const Header&);
        AddPosition¹Command(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        AddPosition¹Command(const AddPosition¹Command&) = delete;
        AddPosition¹Command(AddPosition¹Command&&) = delete;
        AddPosition¹Command& operator=(const AddPosition¹Command&) = delete;
        AddPosition¹Command& operator=(AddPosition¹Command&&) = delete;
    };
}
