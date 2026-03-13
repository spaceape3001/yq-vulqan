////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale²DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale²DCommand, ScaleCommand)
    public:
        MultiplyScale²DCommand(const Header&, const Vector2D&);
    
        const Vector2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MultiplyScale²DCommand(const MultiplyScale²DCommand&, const Header&);
        MultiplyScale²DCommand(const Header&);
        ~MultiplyScale²DCommand();

    private:
        Vector2D  m_δ;
        
        MultiplyScale²DCommand(const MultiplyScale²DCommand&) = delete;
        MultiplyScale²DCommand(MultiplyScale²DCommand&&) = delete;
        MultiplyScale²DCommand& operator=(const MultiplyScale²DCommand&) = delete;
        MultiplyScale²DCommand& operator=(MultiplyScale²DCommand&&) = delete;
    };
}
