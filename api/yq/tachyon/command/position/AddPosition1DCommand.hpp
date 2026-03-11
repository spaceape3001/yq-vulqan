////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPosition¹DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPosition¹DCommand, PositionCommand)
    public:
        AddPosition¹DCommand(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~AddPosition¹DCommand();
        AddPosition¹DCommand(const AddPosition¹DCommand&, const Header&);
        AddPosition¹DCommand(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        AddPosition¹DCommand(const AddPosition¹DCommand&) = delete;
        AddPosition¹DCommand(AddPosition¹DCommand&&) = delete;
        AddPosition¹DCommand& operator=(const AddPosition¹DCommand&) = delete;
        AddPosition¹DCommand& operator=(AddPosition¹DCommand&&) = delete;
    };
}
