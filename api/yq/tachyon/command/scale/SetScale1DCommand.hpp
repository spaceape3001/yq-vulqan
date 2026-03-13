////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale¹DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScale¹DCommand, ScaleCommand)
    public:
        SetScale¹DCommand(const Header&, const Vector1D&);
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_meta();
        
        double  x() const { return m_scale.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~SetScale¹DCommand();
        SetScale¹DCommand(const SetScale¹DCommand&, const Header&);
    

    private:
        Vector1D  m_scale;
        
        SetScale¹DCommand(const SetScale¹DCommand&) = delete;
        SetScale¹DCommand(SetScale¹DCommand&&) = delete;
        SetScale¹DCommand& operator=(const SetScale¹DCommand&) = delete;
        SetScale¹DCommand& operator=(SetScale¹DCommand&&) = delete;
    };
}
