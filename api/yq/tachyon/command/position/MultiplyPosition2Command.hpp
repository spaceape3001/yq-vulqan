////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyPosition²DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition²DCommand, PositionCommand)
    public:
        MultiplyPosition²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyPosition²DCommand(const MultiplyPosition²DCommand&, const Header&);
        MultiplyPosition²DCommand(const Header&);
        ~MultiplyPosition²DCommand();

    private:
        Vector2D  m_δ;
        
        MultiplyPosition²DCommand(const MultiplyPosition²DCommand&) = delete;
        MultiplyPosition²DCommand(MultiplyPosition²DCommand&&) = delete;
        MultiplyPosition²DCommand& operator=(const MultiplyPosition²DCommand&) = delete;
        MultiplyPosition²DCommand& operator=(MultiplyPosition²DCommand&&) = delete;
    };
}
