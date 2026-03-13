////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale¹DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale¹DCommand, ScaleCommand)
    public:
        MultiplyScale¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MultiplyScale¹DCommand();
        MultiplyScale¹DCommand(const MultiplyScale¹DCommand&, const Header&);
        MultiplyScale¹DCommand(const Header&);
    

    private:
        Vector1D  m_δ;
        
        MultiplyScale¹DCommand(const MultiplyScale¹DCommand&) = delete;
        MultiplyScale¹DCommand(MultiplyScale¹DCommand&&) = delete;
        MultiplyScale¹DCommand& operator=(const MultiplyScale¹DCommand&) = delete;
        MultiplyScale¹DCommand& operator=(MultiplyScale¹DCommand&&) = delete;
    };
}
