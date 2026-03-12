////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to multiply it's scale
    class MultiplyMinSize³DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize³DCommand, SizeCommand)
    public:
        MultiplyMinSize³DCommand(const Header&, const Vector3D&);
    
        const Vector3D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double  δx() const { return m_δ.x; }
        double  δy() const { return m_δ.y; }
        double  δz() const { return m_δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize³DCommand(const MultiplyMinSize³DCommand&, const Header&);
        MultiplyMinSize³DCommand(const Header&);
        ~MultiplyMinSize³DCommand();

    private:
        Vector3D  m_δ;
        
        MultiplyMinSize³DCommand(const MultiplyMinSize³DCommand&) = delete;
        MultiplyMinSize³DCommand(MultiplyMinSize³DCommand&&) = delete;
        MultiplyMinSize³DCommand& operator=(const MultiplyMinSize³DCommand&) = delete;
        MultiplyMinSize³DCommand& operator=(MultiplyMinSize³DCommand&&) = delete;
    };
}
