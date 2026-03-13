////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyScale⁴DCommand : public ScaleCommand {
        YQ_OBJECT_DECLARE(MultiplyScale⁴DCommand, ScaleCommand)
    public:
        MultiplyScale⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δw() const { return m_δ.w; }
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyScale⁴DCommand(const MultiplyScale⁴DCommand&, const Header&);
        MultiplyScale⁴DCommand(const Header&);
        ~MultiplyScale⁴DCommand();

    private:
        Vector4D  m_δ;
        
        MultiplyScale⁴DCommand(const MultiplyScale⁴DCommand&) = delete;
        MultiplyScale⁴DCommand(MultiplyScale⁴DCommand&&) = delete;
        MultiplyScale⁴DCommand& operator=(const MultiplyScale⁴DCommand&) = delete;
        MultiplyScale⁴DCommand& operator=(MultiplyScale⁴DCommand&&) = delete;
    };
}
