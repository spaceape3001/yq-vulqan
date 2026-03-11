////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition¹DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition¹DCommand, PositionCommand)
    public:
        MultiplyPosition¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyPosition¹DCommand();
        MultiplyPosition¹DCommand(const MultiplyPosition¹DCommand&, const Header&);
        MultiplyPosition¹DCommand(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyPosition¹DCommand(const MultiplyPosition¹DCommand&) = delete;
        MultiplyPosition¹DCommand(MultiplyPosition¹DCommand&&) = delete;
        MultiplyPosition¹DCommand& operator=(const MultiplyPosition¹DCommand&) = delete;
        MultiplyPosition¹DCommand& operator=(MultiplyPosition¹DCommand&&) = delete;
    };
}
